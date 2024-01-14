#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int status;
  int fd = open(argv[1], O_RDONLY);

  if (fd == -1) {
    printf("open err\n");
    exit(1);
  }

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    int fd[2];
    pipe(fd);

    int id2 = fork();

    if (id2 == -1) {
      printf("inner fork err\n");
      exit(1);
    } else if (id2 == 0) {
      // в детето само ще пишем
      close(fd[0]);
      close(1);
      dup(fd[1]);
      close(fd[1]);
      if (execlp("who", "who", 0) == -1) {
        printf("who err\n");
        exit(1);
      }
    } else {
      // в родителя само ще четем от тръбата
      close(fd[1]);
      close(0);
      dup(fd[0]);
      close(fd[0]);
      if (execlp("wc", "wc", "-l", 0) == -1) {
        printf("wc err\n");
        exit(1);
      }
    }
  } else {
    wait(&status);
    if (status == 0) {
      printf("File content:\n");
      int r;
      char buff[20];
      while ((r = read(fd, buff, sizeof(buff))) > 0) {
        write(1, buff, r);
      }
    }
  }
}