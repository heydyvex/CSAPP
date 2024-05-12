#include <stdio.h>

int main() {

  int number = 12;
  unsigned char *start = (unsigned char *)&number;

  if (start[0] == 12)
    printf("True");
  else
    printf("False");
}