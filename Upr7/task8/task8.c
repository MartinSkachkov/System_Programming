#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd1 == -1 || fd2 == -1) {
    printf("err in open\n");
    exit(1);
  }

  int id = fork();
  if (id == -1) {
    printf("err in fork\n");
    exit(1);
  } else if (id == 0) {
    // the redirection of stdout will be only in the child process(parent is not affected)
    int sout = dup(1);
    close(1);
    dup(fd2);
    write(1, "hello2\n", 7);

    // restore
    close(1);
    dup(sout);
    close(sout);

    // exit(0);
  } else {
    // wait(NULL);
    write(fd1, "hello1\n", 7);
    // exit(0);
  }

  write(1, "hello3\n", 7);
  write(fd2, "hello4\n", 7);
}