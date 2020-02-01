#include <stdio.h>

int main() {
  float grades[6] = {[0] = 10.0, [1] = 105.3};
  int count = 6, i;
  float sum = grades[0] + grades[1];
  float average = 0; 

  for(i = 2; i < count; ++i) {
    printf("%d\t", i+1);
    scanf("%f", &grades[i]);
    sum+=grades[i];
  }

  average = (float) sum/count;
  printf("El promedio es: %f\n",average);

  return 0;
}