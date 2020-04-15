#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 1024
#define MAXINPUT 10240
#define DEF_NUM_LINES 10

// Declarar funciones
int getlines(char *buffer);
void parse_args(int argc, char **argv);

char linestr[MAXINPUT];
char *lineptr[MAXLINES];

int num_of_lines = DEF_NUM_LINES;

int main(int argc, char *argv[])
{
  int lines;
  int ltp = 0;
  int i;
  int c;

  *lineptr = linestr;

  // Filtrar los argumentos que se le pasan al programa
  if (argc > 1)
  {
    parse_args(argc, argv);
  }

  // Obtener el input del usuario
  lines = getlines(linestr);

  if (num_of_lines == 0)
  {
    num_of_lines = 10;
  }

  ltp = lines < num_of_lines ? lines : num_of_lines;
  printf("\n>>> Imprimiendo %d líneas:\n", ltp);

  if (ltp == DEF_NUM_LINES)
  {
    printf("El número de líneas por defecto a imprimir:");
    printf("%d\n", DEF_NUM_LINES);
  }

  printf("\n");

  for (i = lines; i > 0; i--)
  {
    while ((c = *lineptr[0]++) != '\n')
    {
      if (i <= ltp)
      {
        printf("%c", c);
      }
    }
    if (c == '\n' && i <= ltp)
    {
      printf("\n");
    }
  }

  return 0;
}

/*
Obtiene líneas del input
*/
int getlines(char *buffer)
{
  int i, count = 0;
  char c;

  // Iterar hasta que el caracter sea el final de la línea o hasta que sobrepase el tamaño del input máximo
  for (i = 0; (c = getchar()) != EOF && i < MAXINPUT; i += 1)
  {
    // Guardar caracter
    *buffer++ = c;

    // Verificar si el caracter es un salto de línea
    if (c == '\n')
    {
      lineptr[++count] = buffer;
    }
  }

  // Agregar final de la línea
  *buffer++ = '\0';

  return count;
}

/*
Filtra los argumentos
*/
void parse_args(int argc, char **argv)
{
  char c;

  while (--argc > 0 && (*++argv)[0] == '-')
  {
    c = *++argv[0];

    switch (c)
    {
    case 'n':
      num_of_lines = atoi(*(argv + 1));
      break;
    }
  }
}