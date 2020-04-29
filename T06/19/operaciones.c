#include <stdio.h>
#include <stdlib.h>

// Declarar funciones
int sum(int *a, int *b);
int substraction(int *a, int *b);
int multiplication(int *a, int *b);
float division(int *a, int *b);
void print_results(float *results, int n);

int main(void) {
  // Almacenar decisión del usuario
  char should_exit;

  // Realizar operaciones mientras el usuario no quiera salir del programa
  do {
    // Inicializar apuntadores enteros
    int *a = (int *) malloc(sizeof(int));
    int *b = (int *) malloc(sizeof(int));

    // Crear lista para almacenar los resultados
    int n = 0;
    float *results = (float *) malloc(sizeof(float) * n);

    // Pedir datos
    printf("Ingresa el primer número: ");
    scanf("%d", a);

    printf("Ingresa el segundo número: ");
    scanf("%d", b);

    // Reealizar operaciones
    int sum_result = sum(a, b);
    int substraction_result = substraction(a, b);
    int multiplication_result = multiplication(a, b);
    
    if (*(b) != 0) {
      int division_result = division(a, b);
      // Almacenar las operaciones en la lista
      results = (float *) realloc(results, sizeof(float) * 4);

      *(results) = sum_result;
      *(results + (++n)) = substraction_result;
      *(results + (++n)) = multiplication_result;
      *(results + (++n)) = division_result;
    } else {
      // Almacenar las operaciones en la lista
      results = (float *) realloc(results, sizeof(float) * 3);

      *(results) = sum_result;
      *(results + (++n)) = substraction_result;
      *(results + (++n)) = multiplication_result;
    }

    print_results(results, n);

    printf("¿Quieres sali?\ns = sí\nn = no\n");
    scanf(" %c", &should_exit);

    // Liberar la memoria de la lista
    free(results);
  } while (should_exit != 's');

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

// Imprime los resultados
void print_results(float *results, int n) {
  printf("***** RESULTADOS: *****\n");

  for(int i = 0; i < n + 1; i++) {
    // Imprimir suma
    if (i == 0) {
      printf("Suma = %.2f\n", *(results + i));
    } else if (i == 1) {
      printf("Resta = %.2f\n", *(results + i));
    } else if (i == 2) {
      printf("Multiplicación = %.2f\n", *(results + i));
    } else if (i == 3) {
      printf("División = %.2f\n\n", *(results + i));
    }
  }
}