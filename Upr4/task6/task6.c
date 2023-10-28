#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char buff[20];

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./prog.exe f1 f2\n");
    exit(1);
  }

  int file1 = open(argv[1], O_RDONLY);
  int file2 = open(argv[2], O_WRONLY | O_CREAT, 0644);

  if (file1 == -1 || file2 == -1) {
    printf("open error\n");
    exit(1);
  }

  // redirecting stdin to be file1
  //  0 -> argv[1]

  close(0);
  dup(file1);

  // redirecting stdout to be file2
  //  1 -> argv[2]

  close(1);
  dup(file2);

  // copy
  int r;
  while ((r = read(0, buff, 20)) > 0) {
    if (write(1, buff, r) != r) {
      printf("write error\n");
      exit(1);
    }
  }
}