#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int id1 = fork();
  if (id1 == -1) {
    printf("err in first f\n");
    exit(1);
  }

  int id2 = fork();
  if (id2 == -1) {
    printf("err in second f\n");
    exit(1);
  }

  int id3 = fork();
  if (id3 == -1) {
    printf("err in third f\n");
    exit(1);
  }

  printf("HELLO!\n");
}