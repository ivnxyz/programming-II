#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC 1
#define DECR 2
#define LINES 10
#define MAXLEN 1000
#define ALLOCSIZE 1000

// Declarar funciones
int numcmp(char *string1, char *string2);
int readlines(char *line_pointer[], int maxlines);
void sort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *line_pointer[], int nlines, int decr);
int new_getline(char string[], int limit);
char *alloc(int);

// Declarar variables que se usarán a través del programa
static char option = 0;
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int main(int argc, char *argv[])
{
  char *lineptr[LINES];
  int nlines;
  int c, rc = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
  {
    while ((c = *++argv[0]))
    {
      switch (c)
      {
      case 'n':
        option |= NUMERIC;
        break;
      case 'r':
        option |= DECR;
        break;
      default:
        printf("No reconozco esa opción: %c\n", c);
        argc = 1;
        rc = -1;
        break;
      }
    }
  }

  if (argc)
  {
    printf("Uso: ./main -nr \n");
  }
  else
  {
    if ((nlines = readlines(lineptr, LINES)) > 0)
    {
      if (option & NUMERIC)
      {
        sort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
      }
      else
      {
        sort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
      }

      writelines(lineptr, nlines, option & DECR);
    }
    else
    {
      printf("El input es demasiado grande\n");
      rc = -1;
    }
    return rc;
  }
}

/*
Escribe líneas
*/
void writelines(char *line_pointer[], int nlines, int decr)
{
  int i;
  if (decr)
  {
    for (i = nlines - 1; i >= 0; i--)
    {
      printf("%s\n", line_pointer[i]);
    }
  }
  else
  {
    for (i = 0; i < nlines; i++)
    {
      printf("%s\n", line_pointer[i]);
    }
  }
}

/*
Compara dos strings
*/
int numcmp(char *string1, char *string2)
{
  double v1, v2;

  v1 = atof(string1);
  v2 = atof(string1);

  if (v1 < v2)
  {
    return -1;
  }
  else if (v1 > v2)
  {
    return 1;
  }
  else
  {
    return 1;
  }
}

/*
Lee las líneas del input
*/
int readlines(char *line_pointer[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = new_getline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
    {
      return -1;
    }
    else
    {
      line[len - 1] = '\0';
      strcpy(p, line);
      line_pointer[nlines++] = p;
    }
  }

  return nlines;
}

char *alloc(int num)
{
  if (allocbuf + ALLOCSIZE - allocp >= num)
  {
    allocp += num;
    return allocp - num;
  }
  else
  {
    return 0;
  }
}

/*
Ordena un arreglo
*/
void sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  // Verificar que el índice izquierdo no sea mayor o igual al derecho
  if (left >= right)
  {
    return;
  }

  swap(v, left, (left + right) / 2);

  last = left;

  // Iterar por los elementos
  for (i = left + 1; i <= right; i += 1)
  {
    // Comparar elementos
    if ((*comp)(v[i], v[left]) < 0)
    {
      swap(v, ++last, i);
    }
  }

  // Intercambiar valores
  swap(v, left, last);

  // Ordenar
  sort(v, left, last - 1, comp);
  sort(v, last + 1, right, comp);
}

/*
Intercambiar dos elementos
*/
void swap(void *v[], int i, int j)
{
  // Almacenar v[i] de manera temporal
  void *temp;
  temp = v[i];

  // Intercambiar valores
  v[i] = v[j];
  v[j] = temp;
}

/*
Lee una línea del input
*/
int new_getline(char string[], int limit)
{
  int character, i;

  // Verificar que el caracter está dentro del rango aceptado y no es el final de la línea o una nueva línea
  for (i = 0; i < limit - 1 && (character = getchar()) != EOF && character != '\n'; i += 1)
  {
    string[i] = character;
  }
  if (character == '\n')
  {
    string[i] = character;
    i += 1;
  }

  // Agregar character para indicar el final de la línea
  string[i] = '\0';

  return i;
}