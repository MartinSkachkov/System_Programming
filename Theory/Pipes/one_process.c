#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_SIZE 30

int main(int argc, char *argv[]) {
  int fd[2]; // array of two file descriptors
  char buff[MAX_SIZE];

  // create a pipe and initialize fd[0] for reading & fd[1] for writing
  if (pipe(fd) == -1) {
    printf("pipe error\n");
    return (1);
  }

  printf("read pipe fd=%d, write pipe fd=%d\n", fd[0], fd[1]);

  // write into the pipe hello world
  if (write(fd[1], "Hello World\n", 12) != 12) {
    printf("write error\n");
    return (1);
  }

  // read from the pipe hello world
  int r;
  if ((r = read(fd[0], buff, MAX_SIZE)) <= 0) {
    printf("read error\n");
    return (1);
  }

  // print what we read
  write(1, buff, r);

  exit(0);
}