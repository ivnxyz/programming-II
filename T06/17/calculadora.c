#include <stdio.h>
#include <stdlib.h>

// Declarar funciones
int sum(int *a, int *b);
int substraction(int *a, int *b);
int multiplication(int *a, int *b);
float division(int *a, int *b);

int main(void) {
  // Inicializar apuntadores enteros
  int *a = (int *) malloc(sizeof(int));
  int *b = (int *) malloc(sizeof(int));

  // Pedir datos
  printf("Ingresa el primer número: ");
  scanf("%d", a);

  printf("Ingresa el segundo número: ");
  scanf("%d", b);

  // Reealizar operaciones
  printf("Suma = %d\n", sum(a, b));
  printf("Resta = %d\n", substraction(a, b));
  printf("Multiplicación = %d\n", multiplication(a, b));
  
  if (*(b) != 0) {
    printf("División = %f\n", division(a, b));
  }

  return 0;
}

int sum(int *a, int *b) {
  return *a + *b;
}

int substraction(int *a, int *b) {
  return *a - *b;
}

int multiplication(int *a, int *b) {
  return *a * (*b);
}

float division(int *a, int *b) {
  return (*a)/(*b);
}