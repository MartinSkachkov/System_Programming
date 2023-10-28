#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);

  if (argc != 2) {
    printf("Usage: ./task1.exe file\n");
    exit(1);
  }

  if (fd == -1) {
    printf("open error\n");
    exit(1);
  }

  int fd_copy = dup(fd);

  if (fd_copy == -1) {
    printf("open error\n");
    exit(1);
  }

  char buff[15];

  int r1 = read(fd, buff, 5);
  printf("\nFrom fd: %d\n", fd);
  write(1, buff, r1);

  int r2 = read(fd_copy, buff, 8);
  printf("\nCopy fd: %d\n", fd_copy);
  write(1, buff, r2);

  close(fd);

  int r;
  while ((r = read(fd_copy, buff, 10)) > 0) {
    if (write(1, buff, r) != r) {
      printf("error in writing\n");
      exit(1);
    }
  }
}