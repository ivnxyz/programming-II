#include <stdio.h>

void say_hello() {
  printf("Hola mundo\n");
}

void calculate_triangle_area() {
  // Pedir datos
  float base;
  float height;

  printf("Ingresa la base: \n");
  scanf("%f", &base);

  printf("Ingresa la altura: \n");
  scanf("%f", &height);

  // Calcular e imprimir área
  float area = (base * height)/2;

  printf("El área es: %.3f\n", area);
}

void say_goodbye() {
  printf("Bye\n");
}

void unknown_choice() {
  printf("No reconozco esa opción :(\n");
}