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

  for (i = 1; i <= 10; i++) {
    sprintf(buff, "%d\n", i);
    write(1, buff, sizeof(buff));
  }

  for (i = 1; i <= 10; i++) {
    write(1, "HELLO\n", 6);
  }
}