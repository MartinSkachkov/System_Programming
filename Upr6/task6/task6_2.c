#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  int fd2 = open(argv[1], O_WRONLY);

  if (fd1 == -1 || fd2 == -1) {
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
    // wait(NULL);
    write(fd2, "Hello", 5);
  }
}