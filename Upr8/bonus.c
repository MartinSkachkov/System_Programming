#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("ERROR: provide 2 commands and 1 filename\n");
    exit(1);
  }

  int fd = open(argv[3], O_WRONLY | O_CREAT | O_APPEND, 0777);
  if (fd == -1) {
    printf("ERROR: can't open file\n");
    exit(1);
  }

  int id = fork();
  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    if (execlp(argv[1], argv[1], 0) == -1) {
      printf("first cmd exec err\n");
      exit(1);
    }
  } else {
    int stat;
    wait(&stat);
    if (stat == 0) {
      write(fd, argv[1], strlen(argv[1]));
    } else {
      write(2, "ERROR: execution unsuccessful\n", sizeof("ERROR: execution unsuccessful\n"));
    }

    if (execlp(argv[2], argv[2], 0) == -1) {
      printf("first cmd exec err\n");
      exit(1);
    }
  }
}