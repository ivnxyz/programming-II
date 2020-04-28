#include <stdio.h>
#include <ctype.h>

int main() {
  // Inicializar arreglo con las vocales
  char vowels[] = {
    'A',
    'E',
    'I',
    'O',
    'U'
  };

  // Apunta al primer elemento del arreglo
  char *pvowels = vowels;

  int i;

  for (i = 0; i < 5; i++) {
    printf("&vowels[%d]: %p, pvowels + %d: %p\n", i, & vowels[i], i, pvowels + i);
  }

  for (i = 0; i < 5; i++) {
    printf("vowels[%d]: %c, *(pvowels + %d): %c\n", i, vowels[i], i, *(pvowels + i));
    // Imprimir vocal en minúsuclas y su código en ASCII
    printf("vowels[%d]: %c, ACII value: %d\n", i, tolower(*(pvowels + i)), tolower(*(pvowels + i)));
  }
  return 0;
}