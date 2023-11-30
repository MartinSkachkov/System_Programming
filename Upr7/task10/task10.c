#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("need 2 args\n");
    exit(1);
  }

  int id1, id2, stat1, stat2, i = -1;

  id1 = fork();
  if (id1 == -1) {
    printf("Error forking for command1\n");
    exit(1);
  } else if (id1 == 0) {
    execlp(argv[1], argv[2], NULL);
    exit(-1); // ако не успее да се изпълни
  } else {
    wait(&stat1);
    if (stat1 == 0) {
      printf("id1: %d\n", id1);
    }
  }

  id2 = fork();
  if (id2 == -1) {
    printf("Error forking for command2\n");
  } else if (id2 == 0) {
    execlp(argv[2], argv[2], 0);
    exit(-1);
  } else {
    wait(&stat2);
    if (stat2 == 0) {
      printf("id2: %d\n", id2);
    }
  }

  if (stat1 != 0 && stat2 != 0) {
    printf("-1\n");
    exit(-1);
  }
}