#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  close(1);                                        // free the fd 1 which is related to stdout
  int file = open("f1", O_CREAT | O_WRONLY, 0644); // now 1 will relate to f1

  if (file == -1) {
    printf("open error\n");
    exit(1);
  }

  printf("File: %d\n", file);

  int i;
  for (i = 1; i <= 10; i++) {
    write(1, "EXAMPLE\n", 8);
  }
}