#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
  int m=4, n=0;
  int * p2;

  /*
  Aquí se usa malloc en lugar de calloc, la principal diferencia entre malloc y calloc es que calloc aloja la memoria necesaria pero también inicializa los elementos en 0, mientras que malloc no los inicializa en 0. Puede ocurrir que los valores sean 0 al usar malloc, pero no está asegurado.
  */
  p2 = (int *) malloc(sizeof(int[m]));

  for(n=0; n<m && n < 16; ++n) {
    // Agregar 4 bytes
    p2 = (int *) realloc(p2, (m + n) * 4);
    // Agregar entero
    *(p2 + m) = -5;
    m += 4;

    if (*(p2+n) != -5) {
      *(p2+n)+=n*n;
    }

    
    printf("p2[%d] = %d y %p Bytes, %zu\n", n, *(p2+n), (p2+n), sizeof(p2[n]));
  }
  
  free(p2);
  return 0;  
}