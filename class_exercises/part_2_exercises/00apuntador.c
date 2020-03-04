#include <stdio.h>
#define N 5

int main () {
   int  var1, i; // Aquí se declaran dos variables con su respectivo tipo de dato
   char var2[N];

   printf("Direccion de la variable var1: %p\n", &var1); // Aquí se usa el operador de referencia y se van a definir las variables cuando el usuario ingrese algún dato
   printf("Direccion de la variable var2: %p\n", &var2);

  for(i=0; i < N; i++) { // Aquí se hace uso de la variable i
    printf("Direccion de la variable var2[%i]: %p\n", i, &var2[i]); // Aquí se usa el operador de referencia para acceder al espacio en memoria de var2[i]
  }

   return 0;
}