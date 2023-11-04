#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int file1 = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
  int file2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  if (file1 == -1 || file2 == -1) {
    printf("open error\n");
    exit(1);
  }

  char buff[2];
  while (read(0, buff, 1) > 0) {
    write(file1, buff, 1);

    if (buff[0] == '\t') {
      write(file2, " | ->", 5);
    } else {
      write(file2, buff, 1);
    }
  }
}