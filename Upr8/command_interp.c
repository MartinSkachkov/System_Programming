#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char cmd[20];

int main(int argc, char *argv[]) {

  while (1) {
    write(1, "007>", 4);

    char c;
    int pos = 0;

    // четем команда символ по символ и я записваме в cmd
    while (read(0, &c, 1) > 0) {
      if (c == ' ' || c == '\t') {
        continue;
      }

      if (c == '\n') {
        cmd[pos] = '\0';
        break; // вече сме прочели командата
      }

      cmd[pos] = c;
      pos++;
    }

    if (strcmp(cmd, "quit") == 0) {
      exit(0);
    } else {
      int id = fork();
      if (id == -1) {
        printf("fork err\n");
        exit(1);
      } else if (id == 0) {
        if (execlp(cmd, cmd, 0) == -1) {
          printf("exec err\n");
          exit(1);
        }
      } else {
        int stat;
        wait(&stat);

        if (stat != 0) {
          printf("ERROR: can't execute command\n");
        }
      }
    }
  }
}