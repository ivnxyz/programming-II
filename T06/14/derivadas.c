#include <stdio.h>
#include <stdlib.h>

// Definir estructura para el polinomi
typedef struct {
  int x4;
  int x3;
  int x2;
  int x;
  int c;
} PolinomioDeGradoCuatro;

// Declarar función para guardar las derivadas
void guardar_derivadas(PolinomioDeGradoCuatro * polinomio);

/*
NOTA: Es el mismo archivo de la pregunta 13, pero este implementa funciones creadas por el usuario y paso por referencia :)
*/

int main(void) {
  // Declarar variables para los coeficientes y la constante
  int x4, x3, x2, x, c;

  // Declarar variable para almacenar el polinomio
  PolinomioDeGradoCuatro *polinomio = malloc(sizeof(PolinomioDeGradoCuatro));

  // Pedir polinomio
  printf("Ingresa un plinomio de la siguiente forma:\n");
  printf("ax^4 + bx^3 + gx^2 + hx + c\n\n");
  scanf("%dx^4 + %dx^3 + %dx^2 + %dx + %d", &(polinomio->x4), &(polinomio->x3), &(polinomio->x2), &(polinomio->x), &(polinomio->c));

  // Guardar derivadas del polinomio
  guardar_derivadas(polinomio);

  return 0;
}

// Definir función para guardar la derivada
void guardar_derivadas(PolinomioDeGradoCuatro * polinomio) {
  // Abrir archivo
  FILE *fp = fopen("resultado.txt", "w");

  // Manejar errores
  if (fp == NULL) {
    printf("Ocurrió un error al abrir el archivo\n");
  } else {
    // Guardar primera derivada
    fprintf(fp, "%dx^3 + %dx^2 + %dx + %d |", (polinomio->x4) * 4, (polinomio->x3) * 3, (polinomio->x2) * 2, (polinomio->x));

    // Guardar segunda derivada
    fprintf(fp, "%dx^2 + %dx + %d | ", (polinomio->x4) * 12, (polinomio->x3) * 6, (polinomio->x2) * 2);

    // Guardar tercera derivada
    fprintf(fp, "%dx + %d | ", (polinomio->x4) * 24, (polinomio->x3) * 6);

    // Guardar cuarta derivada
    fprintf(fp, "%d", (polinomio->x4) * 24);

    printf("Se guardaron los resultados en otro archivo\n");
  }
}