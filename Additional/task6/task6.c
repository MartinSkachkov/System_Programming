#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd_file = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
  int status;

  if (fd_file == -1) {
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
      // в детето само записваме в тръбата
      close(fd[0]);
      close(1);
      dup(fd[1]);
      close(fd[1]);
      if (execlp("who", "who", 0) == -1) {
        printf("who err\n");
        exit(1);
      }
    } else {
      // в родителя само четем от тръбата и искаме exec да ни запише резултата във файла подаден като арг.
      close(fd[1]);
      close(0);
      dup(fd[0]);
      close(fd[0]);
      close(1); // правим стандартният изход да ни бъде файлът подаден като арг.
      dup(fd_file);
      if (execlp("wc", "wc", "-l", 0) == -1) {
        printf("wc err\n");
        exit(1);
      }
    }

  } else {
    wait(&status);

    if (status == 0) {
      if (execlp("cat", "cat", argv[1], 0) == -1) {
        printf("cat err\n");
        exit(1);
      }
    }
  }
}