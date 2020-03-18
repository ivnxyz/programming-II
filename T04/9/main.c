#include <stdio.h>

#define SIZE 1000

void readLine(char *);

void readLine(char *buffer)
{
  char ch;

  do
  {
    ch = getchar();
    *buffer++ = ch;
  } while (ch != '\n');

  *buffer = '\0';
}

int main(void)
{
  char line[SIZE];

  printf("Ingresa una línea de texto (máximo %i caracteres):\n", SIZE);
  readLine(line);
  printf("%s", line);
  return 0;
}