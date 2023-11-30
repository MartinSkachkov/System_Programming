#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int id = fork();
  int status;

  if (id == -1) {
    printf("err in fork\n");
    exit(1);
  } else if (id == 0) {
    execlp(argv[1], argv[1], 0);
    exit(-1);
  } else {
    wait(&status);
    printf("s: %d\n", status);
    if (status == 0) {
      execlp(argv[2], argv[2], 0);
    }
  }
}

/*int main(int argc, char *argv[]) {
  int id = fork();
  int status;

  if (id == -1) {
    printf("err in fork\n");
    exit(1);
  } else if (id == 0) {
    execlp(argv[1], argv[1], 0);
  } else {
    wait(&status);
    printf("s: %d\n", status);
    if (status == 0) {
      execlp(argv[2], argv[2], 0);
    } else {
      exit(-1);
    }
  }
}*/