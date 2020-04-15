#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXLEN 100

char *lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN];

// Definir funciones
int getline1(char string[], int lim);
int readlines(char *lineptr[], int maxlines);
int readlines2(char lines[][MAXLEN], int maxlines);

int main(int argc, char *argv[])
{
  /*read things into cache, to be fair. */
  readlines2(lines, MAXLINES);

  if (argc > 1 && *argv[1] == '2')
  {
    printf("Función readlines2()");
    readlines2(lines, MAXLINES);
  }
  else
  {
    printf("Función readlines2()");
    readlines(lineptr, MAXLINES);
  }

  return 0;
}

/*
Obtiene una línea
*/
int getline1(char string[], int lim)
{
  int character, i;

  for (i = 0; i < lim - 1 && (character = getchar()) != EOF && character != '\n'; i++)
  {
    string[i] = character;
  }

  if (character == '\n')
  {
    string[i++] = character;
  }

  string[i] = '\0';

  return i;
}

/*
Lee líneas usando un apuntador
*/
int readlines(char *lineptr[], int max)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;

  while ((len = getline1(line, MAXLEN)) > 0)
  {
    if (nlines >= max || (p = malloc(len)) == NULL)
    {
      return -1;
    }
    else
    {
      line[len - 1] = '\0'; /*delete the newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

/*
Segunda implementación de la función readlines
*/
int readlines2(char lines[][MAXLEN], int maxlines)
{
  int len, nlines;

  nlines = 0;

  while ((len = getline1(lines[nlines], MAXLEN)) > 0)
  {
    if (nlines >= maxlines)
    {
      return -1;
    }
    else
    {
      lines[nlines++][len - 1] = '\0';
    }
  }

  return nlines;
}