#include<stdio.h>

int main() {
  // Declarar variables
  int i, sum = 0, dt;

  // Pedir tamaño del arreglo
  printf("Ingrese el numero de datos a sumar\n");
  scanf("%d", & dt);

  int clases[dt];

  // Pedir los datos individuales
  printf("Ingrese %d numeros\n", dt);

  for (i = 0; i < dt; ++i) {
    // Pedir el número
    scanf("%d", clases + i);
    // Supar número
    sum += *(clases + i);
  }

  /*
  Explicación:

  1) &clases[i] es equivalente a clases+i porque al declarar un arreglo, la variable apunta al primer elemento del arreglo, como es un apuntador se le puede sumar i para acceder a la dirección del siguiente elemento del arreglo

  2) clases[i] es equivalente a *(clases + i) porque, de nuevo, al declarar un arreglo la variable apunta al primer elemento del arreglo, por lo que se le puede sumar i para acceder a la dirección del siguiente elemento en el arreglo, luego se usa el operador de indirección para obtener el valor.
  */

  printf("La suma es %d\n", sum);

  return 0;
}