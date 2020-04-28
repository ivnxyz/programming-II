#include <stdio.h>

int main(void) {
  // Inicializar arreglo con los números
  int numbers[] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9
  };

  // Iterar por los números
  for (int first_counter = 0; first_counter < 9; first_counter++) {
    int first_number = *(numbers + first_counter);

    // Iterar nuevamente
    for (int second_counter = 0; second_counter < 9; second_counter++) {
      int second_number = *(numbers + second_counter);
      
      // Imprimir multiplicación
      printf("%d x %d = %d\n", first_number, second_number, first_number * second_number);
    }

    printf("====================\n");
  }

  return 0;
}