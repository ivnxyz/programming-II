#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

// Variables globales
char buf[BUFSIZE];
int bufp = 0;

// Declarar funciones
int getch(void);
void ungetch(int c);
int getint(int *intPointer);

// Función principal
int main() {
  // Declarar variables
  int SIZE = 5;
  int n, array[SIZE];

  // Pedir dígitos
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
  
  // Imprimir datos
  printf("\nResultado del arreglo: \n\n");

  for (n = 0; n < SIZE; n++) {
    if (n == 0) {
      printf("%d", array[n]);
    } else {
      printf(" %d", array[n]);
    }
  }

  printf("\n");

  return 0;
}

// Función getch
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// Función ungetch
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many caracters\n");
  } else {
    buf[bufp++] = c;
  }
}

int getint(int *intPointer) {
  int c, sign;
  char charSign;

  // Ignorar espacios en blanco
  while (isspace(c = getch()));

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); // No es un número
    return 0;
  }

  // Revisar el signo
  sign = (c == '-') ? -1 : 1;
  charSign = (c == '-') ? '-' : '+';

  // Obtener el siguiente caracter
  if (c == '+' || c == '-') {
    c = getch();

    // Veirificar que c es un número
    if (!isdigit(c) && c != EOF) {
      ungetch(c);
      ungetch(charSign);
      return 0;
    }
  }

  for (*intPointer = 0; isdigit(c); c = getch()) {
    *intPointer = 10 * *intPointer + (c - '0');
  }

  *intPointer *= sign;

  if (c != EOF) {
    ungetch(c);
  }

  return c;
}