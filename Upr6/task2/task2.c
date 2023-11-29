#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("only 2 args!\n");
    exit(1);
  }

  if (execlp("grip", "grip", "int", argv[1], 0) == -1) {
    printf("wrong command\n");
    exit(1);
  }
}