#include <stdio.h>
#define LENGTH 50

void new_strcat(char *, char *);

int main()
{
  // Declarar los strings
  char string1[LENGTH] = "Hola";
  char string2[LENGTH] = " mundo";
  char result_string[LENGTH] = "";

  // Copiar el string2 al string1
  new_strcat(string1, string2);

  // Copiar el string1 al resultado final
  new_strcat(result_string, string1);

  // Imprimir datos
  printf("%s\n", string1);
  printf("%s\n", result_string);
}

/*
Recibir dos parámetros: un string s
y un string t
*/
void new_strcat(char *string1, char *string2)
{
  // Esto sirve para saber si se llegó al final del string1
  while (*string1)
  {
    string1 += 1;
  }

  // Copiar string2 a string1
  while (1)
  {
    if (!(*string1++ = *string2++))
    {
      break;
    }
  }
}