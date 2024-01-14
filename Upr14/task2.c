#include <fcntl.h>
#include <stdio.h>
main(int argc, char *argv[]) {
  int fdi, fdo, k, broi, i = 0, status;
  char buff[40], c;
  if ((fdi = open("fileB", O_RDWR)) == -1) {
    printf("\n Cannot open  \n");
    exit(1);
  }
  if ((fdo = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) {
    printf("\n Cannot open  \n");
    exit(1);
  }

  if (fork() == 0) {
    k = dup(1);
    close(1);
    dup(fdi);
    broi = read(fdi, buff, 40);
    c = buff[i++];
    if (c <= '0' || c >= '9') {
      while (buff[i++] != '\n' && i < broi)
        write(1, "*", 1);
      write(1, "\n", 1);
      close(1);
      dup(k);
      write(1, "*\n", 2);
    } else {
      write(1, buff, broi);
      close(1);
      dup(k);
      write(1, "\n", 1);
    }
    write(fdo, buff, 7);
    write(fdo, "*\n", 2);
    close(fdi);
    close(fdo);
  } else {
    wait(&status);
    close(1);
    dup(fdi);
    execlp("grep", "grep", "c", argv[1], 0);
    execlp("wc", "wc", "-l", 0);
  }
}