#include<stdio.h>

int main() {
  char nombre[] = "Javier Orduz";
  char * puntero = nombre;

  printf("Nombre almacenado %s \n", puntero);

  /*
  En este caso sí se puede modificar el string, se modifica el arreglo y ya que el apuntador sólo contiene la dirección del arreglo, no da un error y al imprimir el nombre, aparece actualizado.
  */
  nombre[6] = '+';
  printf("Nombre actualizado %s \n", nombre);

  return 0;
}