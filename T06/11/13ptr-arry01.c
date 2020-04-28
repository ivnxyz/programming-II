#include <stdio.h>
#include <string.h>

int main() {
  char data[] = {
    "enero y febrero"
  };

  char *ptrdata = data + 1;
  /*
  ¿Qué pasa cuando se inicializa el apuntador en otro valor?
  R = Simplemente se salta la letra anterior en el for, es casi como si no exisitera.
  */

  int i;

  printf("Valores guardados: \n");

  for (i = 0; i < strlen(ptrdata); i++) {
    printf("%c\n", *(ptrdata + i));
  }

  return 0;
}