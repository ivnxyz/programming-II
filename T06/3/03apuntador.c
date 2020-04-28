#include <stdio.h>

const int MAX = 3;

int main () {
  int  var[3] = {10, 100, 200};
  int  i, *ptr;

  ptr = var;

  printf("============ Operador ++ =============\n");
  // Usando el operador --
  /*
  Aquí se puede ver que el apuntador comienza en 0 y se va incrementando hasta que llega al final
  del espacio reservado para el arreglo
  */
  for ( i = 0; i < MAX; i++) {
    printf("Direccion de var[%d] = %p\n", i, ptr );
    printf("\t\t\tValor de var[%d] = %d\n", i, *ptr );
    ptr++;
  }

  printf("============ Operador -- =============\n");

  // Usando el operador --
  /*
  Aquí se puede ver que el apuntador comienza en 2 y se le va restando 1 hasta que llega a la posición 0 del arreglo
  */
  for (; i > 0; i--) {
    ptr--;
    printf("Direccion de var[%d] = %p\n", i - 1, ptr );
    printf("\t\t\tValor de var[%d] = %d\n", i - 1, *ptr );
  }

  return 0;
}