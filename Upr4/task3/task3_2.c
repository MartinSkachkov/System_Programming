#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int file = open("f2", O_CREAT | O_WRONLY, 0644);

  if (file == -1) {
    printf("open error\n");
    exit(1);
  }

  close(1);
  dup(file);

  int i;
  for (i = 1; i <= 10; i++) {
    write(1, "EXAMPLE\n", 8);
  }
}