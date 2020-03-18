#include <stdio.h>

int compareStrings(const char *s1, const char *s2)
{
  int answer;

  while (*s1 == *s2 && *s1++ != '\0' && *s2++ != '\0')
    ;

  if (*s1 < *s2)
    answer = -1;
  else if (*s1 == *s2)
    answer = 0;
  else
    answer = 1;

  return answer;
}

int main(void)
{
  printf("%i\n", compareStrings("string", "string"));
  printf("%i\n", compareStrings("longer_string", "string"));
  printf("%i\n", compareStrings("string", "longer_string"));

  return 0;
}