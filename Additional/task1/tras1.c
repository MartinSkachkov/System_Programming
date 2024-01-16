#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd, j, nb1, status;
  char buff[5];

  if (fork()) {
    wait(&status);
    execlp("wc", "wc", "-c", "fileF.txt", 0); // 12 fileF.txt
  } else {
    j = dup(1);
    if ((fd = open(argv[1], O_RDWR)) == -1) {
      printf("err\n");
      exit(1);
    }
    nb1 = read(0, buff, 4);
    write(j, buff, nb1); // who>

    if (fork()) {
      wait(&status);
      close(1);
      dup(fd);
      nb1 = read(fd, buff, 5); // 1 и fd се движат заедно понеже е dup-нато (x1y2z)
      write(1, buff, nb1);     // x1y2zx1y2zc6
    }

    write(j, buff, 3); // who, x1y
    write(1, "\n", 1); // \n, x1y2zx1y2z\n6
    close(fd);
    close(j);
    exit(0);
  }
}

/*
на стандартния изход:
who>who
x1y12 fileF.txt

във fileF:
x1y2zx1y2z
6
*/