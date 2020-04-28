#include <stdio.h>

int main() {

  char * data[5] = {
    "enero1",
    "enero2",
    "enero3",
    "enero4",
    "enero5"
  };
  int i;

  printf("Valores guardados: \n");

  for (i = 0; i < 5; i++) {
    /*
    El siguiente código funciona porque data es un apuntador que tiene la dirección del primer elemento del arreglo, al sumarle i se accede al elemento i del arreglo, luego con el operador de indirección se obtiene el valor del elemento i del arreglo.
    */
    printf("%s\n", *(data + i));
  }

  return 0;
}