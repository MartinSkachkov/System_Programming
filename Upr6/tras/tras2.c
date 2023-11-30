#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD "wc -l $PWD"

main(int argc, char *argv[]) {
  int fd, i = 2, nb1, status;
  char buf[5];

  if (fork() == 0) {
    ++i;
    exit(0); // оттук надолу детето няма да изпълни нищо
  } else {
    if (execlp(CMD, CMD, 0) == -1) { // execlp("wc -l $PWD","wc -l $PWD",0) което не е вярно(не се пишат така аргументите)
      --i;
      wait(&status);
      printf("Stoinostta na i= %d\n", i);
    } else
      printf("Stoinostta na i= %d\n", i);
  }
}

/*
 *
 * Output:
 *
 * Stoinostta na i= 1
 *
 */