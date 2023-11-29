#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("error: provide 3 commands\n");
    exit(1);
  }

  int id1 = fork();
  int stat1;

  if (id1 == -1) {
    printf("first fork err\n");
    exit(1);
  } else if (id1 == 0) {
    if (execlp(argv[1], argv[1], 0) == -1) {
      exit(1);
    }
  } else {
    int pid = wait(&stat1);
    printf("1pid = %d\nstatus = %d\n", pid, stat1);
  }

  int id2 = fork();
  int stat2;

  if (id2 == -1) {
    printf("second fork err\n");
    exit(1);
  } else if (id2 == 0) {
    if (execlp(argv[2], argv[2], 0) == -1) {
      exit(1);
    }
  } else {
    int pid = wait(&stat2);
    printf("2pid = %d\nstatus = %d\n", pid, stat2);
  }

  int id3 = fork();
  int stat3;

  if (id3 == -1) {
    printf("third fork err\n");
    exit(1);
  } else if (id3 == 0) {
    if (execlp(argv[3], argv[3], 0) == -1) {
      exit(1);
    }
  } else {
    int pid = wait(&stat3);
    printf("3pid = %d\nstatus = %d\n", pid, stat3);
  }
}