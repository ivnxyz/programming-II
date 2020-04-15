#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 500
#define BUFFERSIZE 100
#define NUM '0'

// Declarar funciones
void itoa(int n, char *string);
void reverse(char *string);
void ungetch(int character);
int get_line(char *string, int limit);
int atoi(char *string);
int strindex(char *string, char *stringt);
int getop(char *string);
int getch();
long atol(char *string);
double atof(char *string);
char buf[BUFFERSIZE];
int bufp = 0;

int main()
{
  // Probar las funciones
  int len, i;
  char a[MAXLINE], b[MAXLINE];

  // Obtener datos
  printf("Ingresa un texto: \n");
  get_line(a, MAXLINE);

  printf("Ingresa el substring (vea la defunición de la función) a buscar: \n");
  get_line(b, MAXLINE);

  if (strindex(a, b) != -1)
  {
    printf("Índice: %i\n", strindex(a, b));
  }
  else
  {
    printf("El substring no está en el texto\n");
  }

  char c[MAXLINE], d[MAXLINE];
  // Pedir datos
  printf("Ingresa otro texto: \n");
  get_line(a, MAXLINE);
  reverse(a);

  printf("Texto al revés: %s\n", a);
}

/*
Convierte un string a un long
*/
long atol(char *string)
{
  long int sign, n;

  // Saltarse los espacios
  while (isspace(*string))
  {
    string += 1;
  }

  // Almacenar el signo
  sign = (*string == '-') ? -1 : 1;

  // Saltarse los signos
  if (*string == '+' || *string == '-')
  {
    string += 1;
  }

  for (n = 0; isdigit(*string); string++)
  {
    n = 10 * n + (*string - '0');
  }

  return sign * n;
}

/*
Convertir string a un double
*/
double atof(char *string)
{
  double value, power;
  int i, sign;

  // Saltarse los espacios
  for (i = 0; isspace(*string); string++)
    ;

  sign = (*string == '-') ? -1 : 1;

  if (*string == '+' || *string == '-')
  {
    string += 1;
  }

  for (value = 0.0; isdigit(*string); ++string)
  {
    value = 10.0 * value + (*string - '0');
  }

  if (*string == '.')
  {
    string++;
  }

  for (power = 1.0; isdigit(*string); string++)
  {
    value = 10.0 * value + (*string - '0');
    power *= 10.0;
  }

  return sign * value / power;
}

/**
Convierte n caracteres en string
*/
void itoa(int n, char *string)
{
  int sign;
  char *s0 = string; // Obtener primer caracter

  // Almacenar el signo
  if ((sign = n) < 0)
  {
    n = -n; // Hacer que n sea positivo
  }

  // Generar digitos al revés
  do
  {
    // Obtener el sigiente dígito
    *string++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
  {
    *string++ = '-';
  }

  *string = '\0';

  reverse(s0);
}

/*
Convierte string a un entero
*/
int atoi(char *string)
{
  int sign, n;

  // Saltarse los espacios
  while (isspace(*string))
  {
    string += 1;
  }

  // Almacenar el signo
  sign = (*string == '-') ? -1 : 1;

  // Saltarse el signo
  if (*string == '+' || *string == '-')
  {
    string++;
  }

  for (n = 0; isdigit(*string); string += 1)
  {
    n = 10 * n + (*string - '0');
  }

  return sign * n;
}

/*
Lee una línea y la almacena en string
Regresa el largo de string
*/
int get_line(char *string, int limit)
{
  int character, i;

  for (i = 0; i < limit - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
  {
    *string++ = character;
  }

  if (character == '\n')
  {
    *string++ = character;
    i += 1;
  }

  *string = '\0';

  return i;
}

/*
Invierte un string
*/
void reverse(char *string)
{
  int character;
  char *t;

  for (t = string + strlen(string) - 1; string < t; string++, t--)
  {
    character = *string;
    *string = *t;
    *t = character;
  }
}

/*
Regresa el índice de stringt en string si stringt es un substring de string que empieza en un índice de string y termina donde string termina

Regresa -1 si no es un substring
*/
int strindex(char *string, char *stringt)
{
  char *i, *j, *k;

  for (i = string; *i != '\0'; i++)
  {
    for (j = i, k = stringt; *k != '\0' && *j == *k; j++, k++)
      ;

    if (k > stringt && *k == '\0')
    {
      return i - string;
    }
  }

  return -1;
}

/*
Obtiene el siguiente operador
*/
int getop(char *string)
{
  int c;

  // Saltarse los espacios
  while ((*string = c = getch()) == ' ')
    ;
  *(string + 1) = '\0';

  // Regresa el siguiente caracter si no es un número o un punto decimal
  if (!isdigit(c) && c != '.')
  {
    return c;
  }

  if (isdigit(c))
  {
    while (isdigit(*++string = c = getch()))
      ;
  }

  // Obtener la parte fraccionaria
  if (c == '.')
  {
    while (isdigit(*++string = c = getch()))
      ;
  }

  *string = '\0';

  if (c != EOF)
  {
    ungetch(c);
  }

  return NUM;
}

/*
Obtiene un caracter
*/
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
Regresa un caracter al input
*/
void ungetch(int character)
{
  if (bufp >= BUFFERSIZE)
    printf("ungetch: demasiados caracteres\n");
  else
    buf[bufp++] = character;
}