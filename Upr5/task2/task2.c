#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int file1 = open(argv[1], O_RDONLY);
  int file2 = open(argv[2], O_CREAT | O_WRONLY | O_APPEND, 0644);

  char buff_file[2];
  char buff_sin[2];

  while (read(file1, buff_file, 1) > 0 || read(0, buff_sin, 1) > 0) {
    if (buff_file[0] >= '1' && buff_file[0] <= '9') {
      continue;
    } else {
      write(file2, buff_file, 1);
    }

    if (buff_sin[0] >= '1' && buff_sin[0] <= '9') {
      continue;
    } else {
      write(file2, buff_sin, 1);
    }
  }
}