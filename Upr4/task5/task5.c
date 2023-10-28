#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char buff[20];

int main(int argc, char *argv[]) {
  int i;

  for (i = 1; i <= 10; i++) {
    write(1, "EXAMPLE\n", 8);
  }

  int stdout = dup(1);                                // stdout = 3 -> stdout
  int file = open(argv[1], O_CREAT | O_WRONLY, 0644); // file = 5 -> argv[1]
  close(1);                                           // free fd = 1 not to be stdout
  dup(file);                                          // fd = 1 -> qrgv[1]
  close(file);                                        // free fd = 5

  // another way to do the above:
  // stdout = dup(1);
  // close(1);
  // open(argv[1]);

  if (file == -1) {
    printf("open error\n");
    exit(1);
  }

  for (i = 1; i <= 10; i++) {
    sprintf(buff, "%d\n", i);
    write(1, buff, sizeof(buff));
  }

  // възстановяване
  close(1);    // fd = 1 -> argv[1] destroyed
  dup(stdout); // fd = 1 -> stdout

  for (i = 1; i <= 10; i++) {
    write(1, "HELLO\n", 6);
  }
}