#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
  int arrSize = sizeof(arr) / sizeof(int);

  int start, end;
  int fd[2];

  if (pipe(fd) == -1) {
    printf("pipe err\n");
    exit(1);
  }

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
  } else if (id == 0) {
    start = 0;
    end = arrSize / 2;
  } else {
    start = arrSize / 2;
    end = arrSize;
  }

  int sum = 0;
  for (size_t i = start; i < end; i++) {
    sum += arr[i];
  }

  printf("Partial sum: %d\n", sum);

  if (id == 0) {
    close(fd[0]);
    write(fd[1], &sum, sizeof(int));
    close(fd[1]);
  } else {
    wait(NULL);
    int childSum;
    close(fd[1]);
    read(fd[0], &childSum, sizeof(int));
    close(fd[0]);

    int total = sum + childSum;
    printf("Total sum: %d\n", total);
  }
}