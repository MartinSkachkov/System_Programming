#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd1 == -1) {
    printf("err in open\n");
    exit(1);
  }

  int id = fork();
  if (id == -1) {
    printf("err in fork\n");
    exit(1);
  } else if (id == 0) {
    write(fd1, "hello2\n", 7);
  } else {
    wait(NULL);
    write(fd1, "hello1\n", 7);
  }
}