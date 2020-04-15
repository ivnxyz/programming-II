#include <stdio.h>
#include <stdlib.h>

// Definir el tamaño máximo de los tabuladores
#define TABS 4

int main(int argc, char *argv[])
{
  // Declarar variables globales
  int c, pos, i;
  int tabsize[2] = {TABS, TABS};

  while (--argc > 0 && (**++argv == '-' || **argv == '+'))
    switch (**argv)
    {
    case '-':
      if ((pos = atoi(*argv + 1)) > 0)
      {
        tabsize[0] = pos;
      }

      break;
    case '+':
      if ((pos = atoi(*argv + 1)) > 0)
      {
        tabsize[1] = pos;
      }

      break;
    }

  pos = 0;
  i = 0;

  // Verificar que el caracter no sea el final
  while ((c = getchar()) != EOF)
  {
    // Determinar qué simbolo es
    if (c == '\t')
    {
      while (pos < tabsize[i])
      {
        putchar(' ');
        ++pos;
      }

      pos = 0;

      if (i < 1)
      {
        i++;
      }
    }
    else
    {
      putchar(c);

      if (c == '\n')
      {
        pos = 0;
        i = 0;
      }
      else
      {
        ++pos;

        if (pos == tabsize[i])
        {
          pos = 0;
          if (i < 1)
          {
            i++;
          }
        }
      }
    }
  }

  return 0;
}