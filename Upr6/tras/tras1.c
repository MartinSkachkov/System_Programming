#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char *argv[]) {
  int fd, i = 4, nb1, status;
  char buf[5];

  if (fork() == 0) {
    ++i;
    printf("Stoinostta na i= %d\n", i);
  } else {
    --i;
    exit(0); // оттук надолу родителят няма да изпълни нищо
    wait(&status);
    if (execlp("ls", "ls", "-l", 0) == -1)
      i = i + 1;
    else
      printf("Stoinostta na i= %d\n", i);
  }

  printf("Stoinostta na i= %d\n", i);
}

/*
 *
 * Output:
 *
 * Stoinostta na i= 5
 * Stoinostta na i= 5
 *
 */