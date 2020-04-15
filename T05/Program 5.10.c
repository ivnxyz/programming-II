#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM '0'

// Declarar funciones
void push(double);
double pop(void);

/*
Ejecute el programa de la siguiente forma:
./main 3 10 5 +
./main (número de argumentos) (números) (operación)
*/
int main(int argc, char *argv[])
{
  int type;
  double op2;

  while (--argc > 0)
  {
    type = isdigit((*++argv)[0]) || (*argv)[0] == '.' ? NUM : (*argv)[0];

    switch (type)
    {
    case NUM:
      push(atof(*argv));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("Error: división entre 0\n");
      break;
    default:
      printf("Comando desconocido: %s\n", *argv);
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}

#define MAXVAL 100

double val[MAXVAL];
int sp = 0;

/*
Agrega un elemento al stack
*/
void push(double f)
{
  // Revisar si todavía hay espacio
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("Error: el stack está lleno %g\n", f);
  }
}

/*
Sca un elemento del stack
*/
double pop(void)
{
  // Revisar si hay algún elemento
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("Error: el stack está vacío\n");
    return 0;
  }
}