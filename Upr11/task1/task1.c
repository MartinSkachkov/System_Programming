#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);
  // fd[0] - read
  // fd[1] - write

  int id = fork();
  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    close(fd[0]);            // в детето няма нищо да четем, само ще записваме резултата от who
    close(1);                // тъй като who ще се изпринти на stdout а ние искаме в тръбата, то го затваряме
    dup(fd[1]);              // вече резултатът от exec с who ще се *запише* в тръбата не на stdout
    close(fd[1]);            // не трябва да има повече от 1 fd за всеки край на тръбата
    execlp("who", "who", 0); // execute 'who' writing to pipe write fd
  } else {
    close(fd[1]);                // в родителя няма да пишем нищо в тръбата, а само ще четем от нея
    close(0);                    // тъй като wc -l взима данни от stdin, а ние искаме от тръбата то трябва да го сменим
    dup(fd[0]);                  // слагаме ме стандартният вход да е fd[0], оттам да четем
    close(fd[0]);                // не трябва да има повече от 1 fd за всеки край на тръбата
    execlp("wc", "wc", "-l", 0); // execute 'wc' reading from pipe read fd
  }
}