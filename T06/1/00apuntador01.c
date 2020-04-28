#include <stdio.h>

int main(){
  int var1=6, var2=4; // El tipo de variable es int, aquí también se definen las variables
  int * var1_ap, * var2_ap; // Aquí se usa un operador de dirección de memoria, aquí se declara una variable apuntador

  var1_ap = &var1; // Aquí se usa un operador de dirección de memoria, se guarda una dirección en un apuntador (operador de referencia)
  var2_ap = &var2; // Aquí se usa un operador de dirección de memoria, se guarda una dirección en un apuntador (operador de referencia)

  printf("%p %d\n", var1_ap, var1); // Aquí se llaman la variables
  printf("%p %d\n", var2_ap, var2); // Aquí se llaman la variables
  return 0;
}