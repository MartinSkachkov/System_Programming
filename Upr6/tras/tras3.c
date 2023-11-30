#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main() {
  int pid, status;
  char c = '0', d = 'b'; // применливите в родителя и детето са независими едни от други

  pid = fork();
  if (pid != 0) {
    c = '2';
    wait(&status);
  } else {
    d = 'z';
    write(1, "\n c= ", 5);
    write(1, &c, 1);
  }

  write(1, "\n d= ", 5);
  write(1, &d, 1);
}

/*
 *
 * Output:
 *
 * c= 0
 * d= z
 * d= b
 *
 */