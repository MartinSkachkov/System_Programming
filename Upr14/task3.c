main() {
  int a = 2000;

  if (fork()) {
    a /= 2;
    printf("\nStoinostta na a = % d ", a);
  } else {
    if (fork()) {
      a *= 2;
      printf("\nStoinostta na a = % d ", a);

      if (execlp("ps", "ps", 0) == -1) {
        a = a + 2;
        printf("\nStoinostta na a = % d ", a);
      }
    } else {
      a += 2;
      printf("\nStoinostta na a = % d ", a);
    }
  }
  a++;
  printf("\nStoinostta na a = % d ", a);
}
