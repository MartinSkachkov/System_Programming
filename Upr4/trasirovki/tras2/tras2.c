#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd, j, nb1;
  char buff[5];

  j = dup(1);
  fd = open("fileA", O_RDWR);

  nb1 = read(0, buff, 4);
  write(j, buff, nb1);

  nb1 = read(fd, buff, 5);
  write(1, buff, nb1);
  write(fd, buff, nb1);
  write(j, buff, 3);

  close(fd);
  close(j);
  write(1, "\n", 1);
  execlp("cat", "cat", "fileA", 0);
}