#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./prog com file\n");
    exit(1);
  }

  int status;
  int fd_file = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0644);

  char buff[30];
  int r = read(0, buff, 30);
  printf("%d", r);
  r--;
  buff[r] = '\0';

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    // тук ще правим канала

    int fd[2];
    pipe(fd);

    int id2 = fork();
    if (id2 == -1) {
      printf("inner fork err\n");
      exit(1);
    } else if (id2 == 0) {
      close(fd[0]);
      close(1);
      dup(fd[1]);
      close(fd[1]);

      if (execlp(buff, buff, 0) == -1) {
        printf("cmd1 err\n");
        exit(1);
      }
    } else {
      close(fd[1]);
      close(0);
      dup(fd[0]);
      close(fd[0]);

      if (execlp(argv[1], argv[1], 0) == -1) {
        printf("cmd2 err\n");
        exit(1);
      }
    }

  } else {
    wait(&status);
    printf("status: %d", status);
    write(fd_file, buff, sizeof(buff));
    write(fd_file, argv[1], strlen(argv[1]));
  }
}