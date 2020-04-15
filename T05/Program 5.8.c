#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *month_pointer, int *day_pointer);

int main()
{
  int month = 4;
  int day = 3;

  printf("%d\n", day_of_year(2019, 2, 29));
  printf("%d\n", day_of_year(2019, 2, 28));
  printf("%d\n", month_day(2020, 19, &month, &day));
  printf("Mes: %d, día: %d\n", month, day);
}

/*
Configura el día del año
*/
int day_of_year(int year, int month, int day)
{
  int i, leap;

  if (year < 1)
  {
    printf("Error: el año %d no es un número positivo\n", year);
    return -1;
  }
  if (month < 1 || month > 12)
  {
    printf("Error: el mes %d no está entre 1 y 12\n", month);
    return -2;
  }
  if (day < 1 || day > 31)
  {
    printf("Error: el día %d no está entre 1 y 31\n", day);
    return -3;
  }
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  if (month == 2)
  {
    if (!leap && day > 28)
    {
      printf("Error: Febrero %d tiene máximo 28 días\n", year);
      return -4;
    }
    if (leap && day > 29)
    {
      printf("Error: Febrero %d tiene máximo 29 días\n", year);
      return -5;
    }
  }

  for (i = 1; i < month; i += 1)
  {
    day += daytab[leap][i];
  }

  return day;
}

/*
Configurar mes, día del año
*/
int month_day(int year, int yearday, int *month_pointer, int *day_pointer)
{
  int i, leap;

  if (year < 1)
  {
    printf("Error: el año %d no es un número positivo\n", year);
    return -1;
  }

  if (yearday < 1)
  {
    printf("Error: el día %d debe ser mayor a 0\n", yearday);
    return -2;
  }

  // Verificar si es un año bisiesto
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  if (!leap && yearday > 365)
  {
    printf("Error: el día %d debe ser menor o igual a 365\n", yearday);
    return -3;
  }

  if (leap && yearday > 366)
  {
    printf("Error: el día %d debe ser menor o igual a 366 ya que es un año bisiesto\n", yearday);
    return -4;
  }

  for (i = 1; yearday > daytab[leap][i]; i += 1)
  {
    yearday -= daytab[leap][i];
  }

  *month_pointer = i;
  *day_pointer = yearday;

  return 0;
}