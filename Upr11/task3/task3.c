#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);

  if (argc < 3) {
    printf("prog com1 com2 args2 \n");
    exit(1);
  }

  int id = fork();
  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    close(fd[0]);
    close(1);
    dup(fd[1]);
    close(fd[1]);
    execlp(argv[1], argv[1], 0);
  } else {
    close(fd[1]);
    close(0);
    dup(fd[0]);
    close(fd[0]);
    execvp(argv[2], &argv[2]);
  }
}