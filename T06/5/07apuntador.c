#include<stdio.h>

int main() {
  // Declarar variables
  int c, *pc;

  // Asignar variable
  c = 10;

  // Imprimir direcciones antes de operar las variables
  printf("Dirección de c = %p, valor de c = %d\n", &c, c);
  printf("Dirección de pc = %p, valor de pc = %p\n", &pc, pc);

  pc = &c;
  *pc = c;

  printf("=================================\n");

  // Imprimir direcciones
  printf("Dirección de c = %p, valor de c = %d\n", &c, c);
  printf("Dirección de pc = %p, valor de pc = %p\n", &pc, pc);

  return 0;
}