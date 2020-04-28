#include <stdio.h>
#include <ctype.h>

int main() {
  // Declarar variables
  char * pcM, c;
  pcM = & c;

  printf("Mayúsculas | minúsculas\n\n");

  // Iterar por el diccionario
  for (c = 'A'; c <= 'Z'; c++) {
    // Imprimir  letras
    printf("%c | %c\n", *pcM, tolower(*pcM));
  }

  return 0;
}