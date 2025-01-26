#include <stdio.h>
#include "kaprekar.h"

int main(int argc, char **argv) {
  int k = 0,
      start_int = 0;

  printf("Enter an integer from 1000 to 9998: ");
  scanf("%d", &start_int);

  while (start_int < 1000 || start_int > 9998) {
    printf("Integer is out of bounds, please try again: ");
    scanf("%d", &start_int);
  }

  k = kaprekar(start_int);

  // should be Kaprekar's constant, or 6174
  printf("result: %d\n", k);

  return 0;
}
