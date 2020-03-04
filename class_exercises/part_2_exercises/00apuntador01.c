#include <stdio.h>

int main(){
  int var1=6, var2=4; // Aquí se definen y se declaran dos variables
  int *var1_ap, *var2_ap; // Aquí se declaran dos variables apuntadoras

  var1_ap = &var1; // Aquí se usa el operador de referencia para guardar una dirección en la variable apuntador
  var2_ap = &var2; // Aquí se usa el operador de referencia para guardar una dirección en la variable apuntador

  printf("%p %d\n", var1_ap, var1); // Aquí se hace uso de las variables
  printf("%p %d\n", var2_ap, var2);

  return 0;
}