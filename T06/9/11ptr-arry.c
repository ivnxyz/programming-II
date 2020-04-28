#include<stdio.h>

int main() {
  // Declaración de las variables
  float v1 = 3.4;
  float v2 = 2.9;

  // Declaración del apuntador
  float * ptr_vi;

  // Asignación del apuntador
  ptr_vi = & v1;
  printf("salida uno %f\n", * ptr_vi); // Indirección

  // Se asigna de nuevo el apuntador pero ahora apunta a otra variable
  ptr_vi = & v2;
  printf("salida dos %f\n", * ptr_vi); // Indirección

  return 0;
}