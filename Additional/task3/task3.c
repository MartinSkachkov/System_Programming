#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int stat1, stat_last, pid1;

  int id1 = fork();
  if (id1 == -1) {
    printf("first fork err\n");
    exit(1);
  } else if (id1 == 0) {
    int id = fork();
    if (id == -1) {
      printf("inner fork err\n");
      exit(1);
    } else if (id == 0) {
      if (execlp("ps", "ps", "aux", 0) == -1) {
        printf("ps err\n");
        exit(1);
      }
    } else {
      pid1 = wait(&stat1);
      if (execlp("date", "date", 0) == -1) {
        printf("date err\n");
        exit(1);
      }
    }

  } else {
    wait(NULL);
  }

  int id2 = fork();
  if (id2 == -1) {
    printf("second fork err\n");
    exit(1);
  } else if (id2 == 0) {
    if (execvp(argv[1], &argv[1]) == -1) {
      printf("argv err\n");
      exit(1);
    }
  } else {
    wait(NULL);
  }

  int id3 = fork();
  if (id3 == -1) {
    printf("third fork err\n");
    exit(1);
  } else if (id3 == 0) {
    if (execlp("tail", "tail", "-5", "ff", 0) == -1) {
      printf("tail err\n");
      exit(1);
    }
  } else {
    wait(&stat_last);

    if (stat_last == 0) {
      printf("code of exec of first cmd %d\n", stat1);
      printf("pid1 %d\n", pid1);
    }
  }
}