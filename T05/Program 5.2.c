#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define BUFSIZE 100

// Variables globales
char buf[BUFSIZE];
int bufp = 0;

// Declarar funciones
int getch(void);
void ungetch(int c);
int getfloat(float *floatPointer);

// Función principal
int main()
{
  // Declarar variables
  int SIZE = 5;
  int n;
  float array[SIZE];

  // Pedir dígitos
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;

  // Imprimir datos
  printf("\nResultado del arreglo: \n\n");

  for (n = 0; n < SIZE; n++)
  {
    if (n == 0)
    {
      printf("%f", array[n]);
    }
    else
    {
      printf(" %f", array[n]);
    }
  }

  printf("\n");

  return 0;
}

// Función getch
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// Función ungetch
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too many caracters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}

int getfloat(float *floatPointer)
{
  int c, sign;
  char charSign;

  // Ignorar espacios en blanco
  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
  {
    ungetch(c); // No es un número
    return 0;
  }

  // Revisar el signo
  sign = (c == '-') ? -1 : 1;
  charSign = (c == '-') ? '-' : '+';

  // Obtener el siguiente caracter
  if (c == '+' || c == '-')
  {
    c = getch();

    // Veirificar que c es un número
    if (!isdigit(c) && c != EOF)
    {
      ungetch(c);
      ungetch(charSign);
      return 0;
    }
  }

  int counter = 0;

  for (*floatPointer = 0; isdigit(c) || c == '.'; c = getch())
  {
    // Revisar si el caracter es un punto
    if (c == '.')
    {
      counter = 1;
    }
    else
    {
      // Revisar si el contador es 0
      if (!counter)
      {
        //  Calcular resultado de floatPointer
        *floatPointer = 10 * *floatPointer + (c - '0');
      }
      else
      {
        //  Calcular resultado de floatPointer
        // En este caso se le suma el resultado de c - '0' dividido entre algún entero determinado por counter
        // Esto se hace para obtener el resultado como flotante
        *floatPointer = *floatPointer + ((c - '0') / pow(10, counter));
        counter += 1;
      }
    }
  }

  *floatPointer *= sign;

  if (c != EOF)
  {
    ungetch(c);
  }

  return c;
}