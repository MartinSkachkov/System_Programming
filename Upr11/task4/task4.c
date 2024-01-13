#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);

  int id = fork();
  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    close(fd[0]);
    close(1);
    dup(fd[1]);
    close(fd[1]);
    if (execlp("who", "who", 0) == -1) {
      printf("who err\n");
      exit(1);
    }
  } else {
    wait(NULL);

    int id2 = fork();
    if (id2 == -1) {
      printf("fork err\n");
      exit(1);
    } else if (id2 == 0) {
      close(1);
      dup(fd[1]);
      close(fd[1]);

      close(0);
      dup(fd[0]);
      close(fd[0]);
      if (execlp("grep", "grep", "marto", 0) == -1) {
        printf("grep err\n");
        exit(1);
      }
    } else {
      wait(NULL);
      close(fd[1]);
      close(0);
      dup(fd[0]);
      close(fd[0]);
      if (execlp("wc", "wc", "-l", 0) == -1) {
        printf("wc err\n");
        exit(1);
      }
    }
  }
}