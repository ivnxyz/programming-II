#include<stdio.h>

int main() {
  char *nombre = "Javier Orduz.";
  printf("%s\n", nombre);

  // Vamos a modificar el string
  // Si se ejecuta el programa, se verá que da el siguiente error:
  // bus error
  // Por lo que no se puede modificar el string en tiempo de ejecución
  nombre[2] = '+';
  
  printf("%s\n", nombre);

  return 0;
}