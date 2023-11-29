#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("only 2 args!\n");
    exit(1);
  }

  execlp("grep", "grep", "int", argv[1] , 0);
}