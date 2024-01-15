#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("prog.exe niz1 niz2\n");
    exit(1);
  }

  int fd1 = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0644);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  if (fd1 == -1 || fd2 == -1) {
    printf("open err\n");
    exit(1);
  }

  close(0);
  int sin = open("sin", O_RDONLY);

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    int row = 1; // row counter
    char c;

    while (read(0, &c, 1) > 0) {
      if (c == '\n' && row % 2 == 1) { // case когато редът е празен и нечетен, минаваме на следващия
        row++;
      } else if (row % 2 == 1) { // редът не е празен и нечетен
        while (read(0, &c, 1) > 0 && c != '\n') {
          continue; // прочитаме реда без да правим нищо
        }

        row++; // срещнали сме '\n'
      } else { // редът не е празен и четен
        // от външния while сме прочели символ и затова проверяваме
        if (c >= 'a' && c <= 'z') {
          write(fd1, "*", 1); // ако е буква то пишем звезда и продължаваме натам да четем
        } else {
          if (c == '\n') { // ако е празен ред, то пишем само '\n' и продължаваме със следващия нечетен ред
            write(fd1, &c, 1);
            row++;
            continue;
          }
          write(fd1, &c, 1); // ако е символ различен от буква или '\n'
        }

        while (read(0, &c, 1) > 0 && c != '\n') { // проверяваме и останалите от реда
          // заменя всяка буква със символа ‘*‘
          if (c >= 'a' && c <= 'z') {
            write(fd1, "*", 1);
          } else {
            write(fd1, &c, 1);
          }
        }

        write(fd1, "\n", 1);
        row++;
      }
    }
  } else {
    wait(NULL);
    close(1);
    dup(fd2);

    int counter = 0;
    char c;
    char buff[10];

    lseek(fd1, 0, SEEK_SET); // важно е да се направи понеже fd се споделят между процесите

    while (read(fd1, &c, 1) > 0) {
      if (c == '\n') {
        sprintf(buff, "%d", counter);
        write(1, buff, strlen(buff));
        write(1, &c, 1);
        counter = 0;
      } else {
        counter++;
      }
    }
  }
}