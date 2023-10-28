#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int original_stderr = dup(2); // Създаваме копие на stderr файловия дескриптор

  if (original_stderr == -1) {
    perror("dup");
    return 1;
  }

  close(2); // Затваряме оригиналния stderr файлов дескриптор

  int new_stderr = open("error.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

  if (new_stderr == -1) {
    perror("open");
    return 1;
  }

  // Пренасочваме stderr към новия файл
  dup2(new_stderr, 2);
  close(new_stderr);

  // Сега всичко, което се изпраща към stderr, ще бъде записано в "error.txt"
  fprintf(stderr, "Това е грешка!\n");

  // Възстановяваме оригиналния stderr файлов дескриптор
  dup2(original_stderr, 2);
  close(original_stderr);

  // Сега stderr ще бъде отново насочен към стандартната грешка

  printf("Това е стандартен изход!\n");

  return 0;
}