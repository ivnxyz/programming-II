#include<stdio.h>

#include<stdlib.h>

void Func_Reordenar(int n, int * x);

int main() {
  int i, n, * x;

  printf("Numeros a ingresar\n");
  scanf("%d", & n);
  printf("\n");

  /*
  Aquí se modifica el valor de n

  ¿Qué es lo que pasa?
  El programa pide más datos, es todo lo que pasa. Se reserva más espacio en la lista de números y se le piden más números (2 números más) al usuario.
  */
  n += 2;

  // Asignacion de memoria
  x = (int * ) malloc(n * sizeof(int));
  for (i = 0; i < n; ++i) {
    printf("%d-elemento; x = ", i + 1);
    scanf("%d", x + i);
  }
  // Reordena la lista
  Func_Reordenar(n, x);

  printf("Lista invertida\n");
  for (i = 0; i < n; ++i) {
    printf("%d-elemento x = %d\n", i + 1, *(x + i));
  }

  free(x);
  return 0;
}

void Func_Reordenar(int n, int * x) {
  int i, item, temp;

  for (item = 0; item < n - 1; ++item)
    for (i = item + 1; i < n; ++i) {
      temp = * (x + item);
      *(x + item) = * (x + i);
      *(x + i) = temp;
    }
}