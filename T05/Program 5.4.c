#include <stdio.h>
#include <string.h>
#define LENGTH 50

// Declarar función
int strend(char *string, char *stringt);

int main()
{
  // Declarar variables
  int result;
  char string[LENGTH] = "Hola mundososos";
  char stringt[LENGTH] = "sosos";

  // Usar la función
  result = strend(string, stringt);

  // Imprimir resultado
  if (result)
  {
    printf("Stringt SÍ está en string\n");
  }
  else
  {
    printf("Stringt NO está en string\n");
  }
}
