#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);
  // fd[0] - read
  // fd[1] - write

  int id = fork(); // родителят и детето наследяват собствени файлови дескриптори за тръбата, които не са зависими

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    // записваме стойност в тръбата
    close(fd[0]);            // няма да четем нищо в детето
    write(fd[1], "dete", 4); // записваме "dete" в тръбата
    close(fd[1]);            // затваряме фд за писане в тръбата
  } else {
    close(fd[1]); // няма да пишем нищо в тръбата от родителя
    char buff[10];
    int r = read(fd[0], buff, 10);
    write(1, buff, r);
    close(fd[0]);
  }
}