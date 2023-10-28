#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./prog.exe file1 file2\n");
    exit(1);
  }

  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

  if (fd1 == -1 || fd2 == -1) {
    printf("error in opening\n");
    exit(1);
  }

  int lineCount = 1;
  int count_read = 0;
  char buffer[61];
  int r;
  char prev;
  bool special_line = false;

  while ((r = read(fd1, buffer, 1)) > 0) {
    count_read++;
    if (buffer[0] == '$') {
      lseek(fd1, -count_read, SEEK_CUR);
      read(fd1, buffer, count_read + 1);
      write(1, buffer, count_read + 1);
      special_line = true;
    }

    if (prev != '$' && buffer[0] == '\n') {
      // if (!special_line) {
      lseek(fd1, -count_read, SEEK_CUR);
      while ((r = read(fd1, buffer, 1)) > 0) {
        if (buffer[0] >= '0' && buffer[0] <= '9') {
          write(fd2, buffer, 1);
          write(fd2, "\n", 1);
        }

        if (buffer[0] == '\n') {
          break;
        }
      }
      // }

      // if (special_line == true) {
      //  special_line = false;
      //}
      count_read = 0;
    }

    prev = buffer[0];
  }
}