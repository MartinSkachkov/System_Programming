#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  int copy = dup(fd1);

  if (fd1 == -1) {
    printf("open err\n");
    exit(1);
  }

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    write(fd1, "hello", 5);
  } else {
    wait(NULL);
    write(copy, "HelloP", 6);
  }
}