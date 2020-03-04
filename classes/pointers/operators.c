#include <stdio.h>

int main() {
  // Variable entera
  int age = 19;

  // Operador de indireccion
  int *ip; // Esto almacena una dirección en memoria

  // Operador de referencia
  ip = &age; // Aquí se le asigna a ip la dirección de age

  printf("ip: %p\n", ip); // Aquí se accede a la dirección que guarda ip
  printf("ip: %d\n", *ip); // Aquí se accede al valor de ip
  printf("age: %d\n", age); // Aquí se accede al valor de age
  printf("age: %p\n", &age); // Aquí se accede a la dirección de age
  // printf("age: %d\n", *age); <- Esto da un error porque el operador de indirección actúa sobre un apuntador

  return 0;
}