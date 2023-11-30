#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int id1 = fork();

  if (id1 == -1) {
    printf("error in fork\n");
    exit(1);
  } else if (id1 == 0) {
    int id2 = fork();
    if (id2 == -1) {
      printf("error in child fork\n");
      exit(1);
    } else if (id2 == 0) {
      printf("Child Process - PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
      wait(NULL);
      printf("My process ID is %d and my parent is %d\n", getpid(), getppid());
    }
  } else {
    wait(NULL);
    printf("My process ID is %d and my parent is %d\n", getpid(), getppid());
  }
}