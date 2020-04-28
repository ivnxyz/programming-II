#include <stdio.h>
#define N 5

int main() {
  int var1, i; // El tipo de variable es int, aquí se declara una variable
  char var2[N]; // El tipo de variable es char

  printf("Direccion de la variable var1: %p\n", & var1); // Aquí se llama la variable
  printf("Direccion de la variable var2: %p\n", & var2); // Aquí se llama la variable

  for (i = 0; i < N; i++) {
    printf("Direccion de la variable var2[%i]: %p\n", i, & var2[i]); 
  }

  return 0;
}