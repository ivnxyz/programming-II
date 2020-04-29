#include <stdio.h>
#include <stdlib.h>

void n_power(float * numero, int *veces);
void save_number(float *numero);

int main(void) {
  // Declarar variables
  float num;
  int *veces = (int *) malloc(sizeof(int));

  // Pedir número
  printf("De un valor: ");
  scanf("%f", &num);

  // Pedir potencia
  printf("Cuántas veces lo quiere multiplicar: ");
  scanf("%d", veces);

  // Multiplicar n veces
  n_power(&num, veces);

  // Guardar número
  save_number(&num);

  return 0;
}

// Multiplica un número por sí mismo n veces
void n_power(float *numero, int *veces) {
  // Copiar el número
  int number_copy = *numero;

  // Multiplicar n veces el número
  for (int i = 0; i < *veces; i++) {
    // Multiplicar el número
    *numero = *numero * number_copy;
  }
}

// Guarda el número en un archivo externo
void save_number(float *numero) {
  // Abrir archivo
  FILE *filePointer = fopen("multiplicacion.txt", "w");

  // Guardar resultado
  fprintf(filePointer, "%f", *numero);

  printf("Se guardó el número en otro archivo :)\n");
}