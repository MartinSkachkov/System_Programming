#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // създава/отваря_съществуващ файл;
  int fd = open("file", O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (fd == -1) {
    printf("open err\n");
    exit(1);
  }

  // инициализира/записва в началото му начална числова стойност  (примерно  0);
  int n = 0;
  write(fd, &n, sizeof(int));

  // стартира нов процес  (примитив fork);
  int id = fork();
  int prom;
  char buff[30];

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    for (size_t i = 1; i <= 1000; i++) {
      lseek(fd, 0, 0);
      read(fd, &prom, sizeof(int));
      prom++;
      sprintf(buff, "\t\tchild: %d\n", prom);
      write(1, buff, strlen(buff));
      lseek(fd, 0, 0);
      write(fd, &prom, sizeof(int));
    }
  } else {
    for (size_t i = 1; i <= 2000; i++) {
      lseek(fd, 0, 0);
      read(fd, &prom, sizeof(int));
      prom += 2;
      sprintf(buff, "parent: %d\n", prom);
      write(1, buff, strlen(buff));
      lseek(fd, 0, 0);
      write(fd, &prom, sizeof(int));
    }
  }

  lseek(fd, 0, 0);
  read(fd, &prom, sizeof(int));
  sprintf(buff, "\n Final val: %d\n", prom);
  write(1, buff, strlen(buff));
}