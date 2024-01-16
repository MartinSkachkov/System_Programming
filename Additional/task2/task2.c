#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
  int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);

  int status;

  if (fd1 == -1 || fd2 == -1) {
    printf("open err\n");
    exit(1);
  }

  if (argc != 4) {
    write(fd1, "greshka\n", 8);
    exit(1);
  }

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    if (execlp("cp", "cp", argv[2], "/home/marto/Desktop/f1", 0) == -1) { // exec-a ще изтрие всички в детето надолу
      printf("cp err\n");                                                 // и все едно само родителя продължава
      exit(1);
    }
  } else {
    wait(NULL);
  }

  int fd3 = open(argv[3], O_RDWR);

  int id2 = fork();

  if (id2 == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    char buff[20];
    read(fd3, buff, 20);

    close(0);
    dup(fd1);
    close(2);
    dup(fd2);

    if (execlp(buff, buff, 0) == -1) {
      printf("exec err\n");
      exit(1);
    }

  } else {
    wait(&status);

    printf("stat: %d\n", status);
    execlp("date", "date", 0);
  }
}