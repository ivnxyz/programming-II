#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define MDIR 8
#define LINES 100
#define MAXLEN 1000
#define ALLOCSIZE 10000

// Declarar funciones
int charcmp(char *string1, char *string2);
int numcmp(char *string1, char *string2);
int readlines(char *lineptr[], int maxlines);
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *line_pointer[], int nlines, int decr);
int new_getline(char string[], int limit);
char *alloc(int num);

// Declarar funciones que se usarán a través del programa
static char option = 0;
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int main(int argc, char *argv[])
{
  char *lineptr[LINES];
  int nlines;
  int c, rc = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c)
      {
      case 'd':
        option |= MDIR;
        break;
      case 'f':
        option |= FOLD;
        break;
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

  if (argc)
  {
    printf("Uso: ./main -dfnr\n");
  }
  else
  {
    if ((nlines = readlines(lineptr, LINES)) > 0)
    {
      if (option & NUMERIC)
      {
        myqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp);
      }
      else
      {
        myqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp);
      }

      writelines(lineptr, nlines, option & DECR);
    }
    else
    {
      printf("El input es demasiado grande\n");
      rc = -1;
    }
  }

  return rc;
}

/*
Compara dos strings de caracteres
*/
int charcmp(char *string1, char *string2)
{
  char a, b;
  int fold = (option & FOLD) ? 1 : 0;
  int dir = (option & MDIR) ? 1 : 0;

  do
  {
    if (dir)
    {
      while (!isalnum(*string1) && *string1 != ' ' && *string1 != '\0')
      {
        string1++;
      }
      while (!isalnum(*string2) && *string2 != ' ' && *string2 != '\0')
      {
        string2++;
      }
    }
    a = fold ? tolower(*string1) : *string1;
    string1++;

    b = fold ? tolower(*string2) : *string2;
    string2++;

    if (a == b && a == '\0')
    {
      return 0;
    }

  } while (a == b);

  return a - b;
}

/*
Compara dos strings de números
*/
int numcmp(char *string1, char *string2)
{
  double v1, v2;
  v1 = atof(string1);
  v2 = atof(string2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

/*
Intercambiar dos elementos
*/
void swap(void *v[], int i, int j)
{
  // Almacenar v[i] de manera temporal
  char *temp;
  temp = v[i];

  // Intercambiar valores
  v[i] = v[j];
  v[j] = temp;
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
  {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++)
  {
    if ((*comp)(v[i], v[left]) < 0)
    {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);

  myqsort(v, left, last - 1, comp);
  myqsort(v, last + 1, right, comp);
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
    ++i;
  }

  // Agregar character para indicar el final de la línea
  string[i] = '\0';

  return i;
}