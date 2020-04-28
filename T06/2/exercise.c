#include <stdio.h>
#include <stdlib.h>

/*
Realiza código que opere con tres números enteros. Define tres apuntadores, tres variables de tipo float, inicializar las variables en tres números, implementa las cuatro operaciones aritméticas básicas y referencia. Posteriormente, usa el operador de deferenciación para imprimir los resultados de las operaciones. Imprime las direcciones de memoria.
*/

int main () {
   // Definir apuntadores
   float *p1;
   float *p2;
   float *p3;

   // Definir variables
   float v1 = 5.5;
   float v2 = 2.8;
   float v3 = 4.9;

   // Asignar apuntadores
   p1 = &v1;
   p2 = &v2;
   p3 = &v3;

   // Operaciones aritméticas
   float * r2 = (float *) malloc(sizeof(float));
   float * r1 = (float *) malloc(sizeof(float));
   float * r3 = (float *) malloc(sizeof(float));
   float * r4 = (float *) malloc(sizeof(float));

   // Asignar resultados
   *r1 = (*p1) + (*p2) + (*p3);
   *r2 = (*p1) - (*p2) - (*p3);
   *r3 = (*p1) * (*p2) * (*p3);
   *r4 = ((*p1) / (*p2));
   *r4 = (*r4)/(*p3);

   // Imprimir datos
   printf("Suma = %p, %.2f\n", r1, *r1);
   printf("Resta = %p, %.2f\n", r2, *r2);
   printf("Multiplicación = %p, %.2f\n", r3, *r3);
   printf("División = %p, %.2f\n", r4, *r4);

   printf("****************\n");
   printf("Apuntador 1 = %p\n", p1);
   printf("Apuntador 2 = %p\n", p1);
   printf("Apuntador 3 = %p\n", p1);
   
   return 0;
}