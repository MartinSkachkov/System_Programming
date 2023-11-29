#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int id = fork();
  int status;

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    if (execlp(argv[1], argv[1], 0) == -1) {
      exit(1);
    }
  } else {
    wait(&status);
    // printf("s:%d p:%d", status, pid);
    if (status == 0) {
      printf("command: %s\n", argv[1]);
    } else {
      printf("wrong command\n");
      exit(1);
    }
  }
}