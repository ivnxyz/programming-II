#include<stdio.h>

int main(void) {
  int mi_arreglo[] = {
    -1,
    2,
    -3,
    4,
    -5
  }, * ptr, i;

  /*
  Aquí se inicializa el apuntador de manera diferente, además se salta el primer elemento
  */
  ptr = mi_arreglo + 1;

  /*
  ¿Qué pasa cuando se inicializa el apuntador en otro valor?
  R = Simplemente se salta el primer número en el for, sin embargo, al sumarse i el último elemento que se imprime en el for no es realmente el último elemento del arreglo.
  */

  for (i = 1; i < 5; i++) {
    printf("*(ptr + %d) = %d \t\tmi_arreglo[%d] = %d \n", i, *(ptr + i), i, mi_arreglo[i]);
  }
  return 0;
}