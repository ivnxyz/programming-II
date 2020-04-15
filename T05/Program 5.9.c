#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

// Declara función
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *month_pointer, int *day_pointer);

int main()
{
  printf("%d\n", day_of_year(2020, 05, 24));
  printf("%d\n", day_of_year(2020, 12, 20));

  int m, d;

  month_day(2020, 200, &m, &d);
  printf("%d/%d\n", m, d);

  month_day(2020, 365, &m, &d);
  printf("%d/%d\n", m, d);
}

int day_of_year(int year, int month, int day)
{
  int leap;
  char *p;

  // Verificar si es un año bisiesto
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  p = *daytab + leap;

  while (--month)
  {
    day += *++p;
  }

  return day;
}

void month_day(int year, int yearday, int *month_pointer, int *day_pointer)
{
  int leap, i;
  char *p;

  // Verificar si es un año bisiesto
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  p = *daytab + leap;

  for (i = 1; yearday > *++p; i++)
  {
    yearday -= *p;
  }

  *month_pointer = i;
  *day_pointer = yearday;
}