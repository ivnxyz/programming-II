#include<stdio.h>
#include<stdlib.h>

#define MAXROWS 20

void leer_entrada(int * a[MAXROWS], int nrows, int ncols);
void cal_suma(int * a[MAXROWS], int * b[MAXROWS], int * c[MAXROWS], int nrows, int ncols);
void escri_salida(int * a[MAXROWS], int nrows, int ncols);

int main() {
  int row, nrows, ncols;
  int * a[MAXROWS], * b[MAXROWS], * c[MAXROWS];

  puts("\t\t\tCuantas filas?");
  scanf("%d", & nrows);
  puts("\t\t\tCuantas columnas?");
  scanf("%d", & ncols);

  // Alojar el tamaño de memoria inicial
  for(row = 0; row < nrows; ++row) {
    a[row] = (int *) malloc (sizeof(int));
    b[row] = (int *) malloc (sizeof(int));
    c[row] = (int *) malloc (sizeof(int));
	}
    
  puts("La primer tabla");
  leer_entrada(a, nrows, ncols);

  puts("La segunda tabla");
  leer_entrada(b, nrows, ncols);

  cal_suma(a, b, c, nrows, ncols);
  puts("Suma de los elementos");
  escri_salida(c, nrows, ncols);

  return 0;
}

void leer_entrada(int * a[MAXROWS], int m, int n) {
  int row, col;

  for (row = 0; row < m; ++row) {
    // Cambiar el tamaño del arreglo de manera dinámica
    a[row] = (int *) realloc(a[row], sizeof(int) * (row + 1));

    printf("De la forma a b c; ingrese datos para la fila %2d\n", row + 1);
    for (col = 0; col < n; ++col) {
      scanf("%d", ( * (a + row) + col));
    }
  }
}

void cal_suma(int * a[MAXROWS], int * b[MAXROWS], int * c[MAXROWS], int m, int n) {
  int row, col;

  for (row = 0; row < m; ++row) {
    for (col = 0; col < n; ++col) {
      /*
      Aquí se usa a[row][col], no pasa nada ya que es equivalente a usar apuntadores
      */
      *( * (c + row) + col) = a[row][col] + b[row][col];
    }
  }
}

void escri_salida(int * a[MAXROWS], int m, int n) {

  int row, col;

  for (row = 0; row < m; ++row) {
    for (col = 0; col < n; ++col) {
      /*
      Aquí se usa a[row][col], no pasa nada ya que es equivalente a usar apuntadores
      */
      printf("%4d", a[row][col]);
    }
    printf("\n");
  }
  return;
}