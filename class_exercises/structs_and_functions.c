#include <stdio.h>
#include <math.h>

// Declarar la estructura
typedef struct Point {
  float x;
  float y;
} Point;

// Declarar funciones
float calculate_diagonal(Point point1, Point point2);
float calculate_perimeter(Point point1, Point point2);

int main() {
  // Declarar los puntos
  Point point1;
  Point point2;
  Point point3;
  Point point4;

  // Pedirle los datos al usuario
  printf("Ingrese las coordenadas de los vértices de su rectángulo\n");
  printf("Ingresa el punto 1 como x, y: ");
  scanf("%f, %f", &point1.x, &point1.y);

  printf("Ingresa el punto 2 como x, y: ");
  scanf("%f, %f", &point2.x, &point2.y);

  printf("Ingresa el punto 3 como x, y: ");
  scanf("%f, %f", &point3.x, &point3.y);

  printf("Ingresa el punto 4 como x, y: ");
  scanf("%f, %f", &point4.x, &point4.y);

  // Declarar variables
  float perimeter = 0;

  // Declarar arreglo de puntos
  Point points[] = {point1, point2, point3, point4};

  // Calcular valores
  for (int i = 1; i < sizeof(points)/sizeof(Point); i++) {
    // Obtener puntos extremos
    if (point1.x != points[i].x && point1.y != points[i].y) {
      // Calcular diagonal
      float diagonal = calculate_diagonal(point1, points[i]);
      printf("Valor de la diagonal: %f\n", diagonal);
    }

    // Obtener puntos en la misma x o y
    if (point1.x == points[i].x || point1.y == points[i].y) {
      // Calcular perímetro
      perimeter += calculate_perimeter(point1, points[i]);
    }
  }

  // Buscar la base y la altura
  float base;
  float height;

  for (int i = 1; i < sizeof(points)/sizeof(Point); i++) {
    if (point1.x == points[i].x) {
      // Calcular altura
      height = point1.y - points[i].y;
    } else if (point1.y == points[i].y) {
      // Calcular base
      base = point1.x - points[i].x;
    }
  }


  // Imprimir datos faltantes
  printf("Perímetro: %f\n", perimeter);
  printf("Área: %f\n", base * height);

  return 0;
}

// Definir función para calcular la diagonal
float calculate_diagonal(Point point1, Point point2) {
  return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

// Definir función para calcular el perímetro
float calculate_perimeter(Point point1, Point point2) {
  return 2 * (point2.x - point1.x) + 2 * (point2.y - point1.y);
}