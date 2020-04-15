#include <stdio.h>
#include <string.h>

#define NEW_NULL '\0'
#define LENGTH 100

// Declarar las funciones
char *new_strncpy(char *string, char *stringt, int n);
char *new_strncat(char *string, char *stringt, int n);
int new_strncmp(char *string, char *stringt, int n);

int main()
{
  // Declarar cadenas de caracteres
  char string1[LENGTH] = "Hola";
  char string2[LENGTH] = "Hola";
  char stringt[LENGTH] = "programaresmipasionxd";

  // Copiar los primeros 3 caracteres de string1 a stringt
  new_strncpy(string1, stringt, 3);
  printf("Resultado de la copia: %s\n", string1);

  // Concatenar 4 caracteres de stringt en string1
  new_strncat(string2, stringt, 4);
  printf("Resultado de la concatenación: %s\n", string2);

  // Comparar los primeros 4 caracteres de string1 y string
  printf("Resultado de la comparación: %d\n", new_strncmp(string1, string2, 1));
}

/*
Copiar máximo n caracteres del stringt a string
Regresa un apuntador al string
*/
char *new_strncpy(char *string, char *stringt, int n)
{
  // Copiar cada elemento de stringt en string
  for (int i = 0; i < n; i += 1)
  {
    *string++ = *stringt++;
  }

  // Verificar si stringt sea menor que n
  if (strlen(stringt) < n)
  {
    while (1)
    {
      // Eliminar los caracteres que sobrepasen a n
      if (!(*string++ = NEW_NULL))
      {
        break;
      }
    }
  }

  return string;
}

/*
Concatena máximo n caracteres de stringt a string
Regresa un apuntador al string
*/
char *new_strncat(char *string, char *stringt, int n)
{
  // Ir al final de string
  while (*string)
  {
    string += 1;
  }

  // Copiar stringt en string con la función ya creada
  return new_strncpy(string, stringt, n);
}

/*
Compara máximo n caracteres de string y stringt
Regresa -1 si hay una diferencia
Regresa 0 si son iguales
*/
int new_strncmp(char *string, char *stringt, int n)
{
  // Comparar los caracteres en un rango n
  for (int i = 0; i < n; i += 1)
  {
    // Verificar que los caracteres sean iguales
    if (*string != *stringt)
    {
      return -1;
    }

    string += 1;
    stringt += 1;
  }

  return 0;
}