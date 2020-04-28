#include <stdio.h>

int main() {
  int var1 = 6, var2 = 4, var3 = 0; // El tipo de variable es int, aquí también se definen las variables
  int * var1_ap, * var2_ap; // Aquí se usa un operador de dirección de memoria

  var1_ap = & var3; // Aquí se usa un operador de dirección de memoria (referencia)
  var3 = var1 + var2;
  printf("%p %d %p %d\n", var1_ap, var3, & var3, * var1_ap); // Aquí se llaman las variables, aquí se accede al valor de una variable apuntador con el operador de dereferencia
  return 0;
}