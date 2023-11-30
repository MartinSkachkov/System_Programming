#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int id1 = fork();
  if (id1 == -1) {
    printf("error in fork\n");
    exit(1);
  }

  if (id1 == 0) {
    write(1, "Hello\n", 6);
  } else {
    wait(NULL);
  }

  int id2 = fork();
  write(1, "Hello1\n", 7);
}