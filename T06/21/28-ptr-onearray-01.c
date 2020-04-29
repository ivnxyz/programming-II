#include<stdio.h>

#define N 5

int main() {
  // Declarar arreglo de 5 elementos
  int v[N];

  // Declarar variables
  int i, * p;

  // Asignar elementos al arreglo
  for (i = 0; i < N; i++) {
    v[i] = i;
  }

  // Imprimir el arreglo usando la notación convencional
  for (i = 0; i < N; i++) {
    printf("%d\n", v[i]);
  }

  // Inicializar apuntador con la dirección del primer elemento del arreglo
  p = v;
  
  // Imprimir el arreglo usando apuntadores
  for (i = 0; i < N; i++) {
    printf("\t%d\n", *(p + i));
  }

  /*
  Reflexión: v[i] y *(p + i) terminan siendo expresiones equivalentes, se puede ver que los datos que imprime el programa son los mismos sin importar los operadores que se usen-
  */

  return 0;
}