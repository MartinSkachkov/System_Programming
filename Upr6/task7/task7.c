#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    printf("open err\n");
    exit(1);
  }

  int id = fork();
  char buff[2];
  int r;

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    write(fd, "Hello", 5);
  } else {
    wait(NULL);
    lseek(fd, 0, SEEK_SET); // get the fd back to the beginning of the file and then read
    while ((r = read(fd, buff, 1)) > 0) {
      write(1, buff, r);
      write(1, " ", 1);
    }
  }
}