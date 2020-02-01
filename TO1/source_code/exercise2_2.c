#include <stdio.h>
#include <stdbool.h>

int main() {
  for (int i = 3; i <= 100; i++) {
    // Revisar que no sea par
    if (i % 2 == 0) {
      continue;
    }

    bool isPrime = true;

    // Iterar por los números primos ya conocidos
    for (int j = 3; j < i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      printf(" %i ", i);
    }
  }

  printf("\n");

  return 0;
}