#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// char *args[10];

int main(int argc, char *argv[]) {
  int id = fork();
  int status;

  // int i;
  // for (i = 1; i < argc; i++) {
  //  args[i] = argv[i];
  //}

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    if (execvp(argv[1], &argv[1]) == -1) {
      exit(1);
    }
  } else {
    wait(&status);
    if (status == 0) {
      printf("stat: %d\n", status);
    }
  }
}