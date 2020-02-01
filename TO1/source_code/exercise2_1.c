# include <stdio.h>

int main () {
  // Arreglo de enteros
  int integers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Iterar arreglo
  int size = sizeof(integers)/sizeof(int);

  for (int i = 0; i < size; i++) {
    printf("%i\n", integers[i]);
  }
  
  return 0;
}