#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int file1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  int file2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644);

  if (file1 == -1 || file2 == -1) {
    printf("open err\n");
    exit(1);
  }

  int id = fork();

  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    close(1);
    dup(file2);
    write(1, "HelloC1", 7);
    write(1, "HelloC2", 7);
  } else {
    write(1, "Hello3", 6);
    write(file2, "HelloP", 6);
  }
  write(1, "HelloCom", 8);
}
