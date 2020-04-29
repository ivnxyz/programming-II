#include<stdio.h>

int main() {
  // Declarar apuntadores
  int * ptr_x, * ptr_y;
  // Definir arreglo de enteros
  int a[6] = {
    50,
    40,
    30,
    20,
    10,
    4
  };
  // Inicializar apuntadores con la dirección del elemento 0 y 5
  ptr_x = & a[0];
  ptr_y = & a[5];

  /*
    Reflexión: La salida de este programa muestra la distancia que hay entre los dos apuntadores, en este caso la distancia es de 5.
  */
  printf("ptr_x = %p; ptr_y = %p\n", ptr_x, ptr_y);
  printf("ptr_y - ptr_x = %d \n", (int)(ptr_y - ptr_x));

  return 0;
}