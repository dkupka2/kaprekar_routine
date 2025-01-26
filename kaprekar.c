#include <stdio.h>
#include <string.h>
#include "kaprekar.h"

int kaprekar(int n) {
  // take parameter int n, and sort the digits in asc. order
  // then subtract that from the previous int sorted in desc order,
  // keep going until you reach 6174 (hopefully within 7 steps)
  // and return

  int minuend = 0,
      subtrahend = 0,
      difference = 0,
      temp = 0,
      i = 0,
      digits[4];

  temp = n;

  // Create minuend and subtrahend

  memcpy(digits, create_array_from_int(digits, temp), sizeof(digits));

  minuend = create_int_from_array(sort_descend(digits));
  printf("Minuend: %d\t", minuend);

  subtrahend = create_int_from_array(sort_ascend(digits));
  printf("Subtrahend: %d\n", subtrahend);

  difference = minuend - subtrahend;

  printf("%d - %d = %d\n\n", minuend, subtrahend, difference);

  if (difference != KAPREKARS_CONSTANT) {
    difference = kaprekar(difference);
  } else {
    return difference;
  }
  return difference;
}

int * create_array_from_int(int *digits, int n) {
      
  int count = 0,
      temp = n;

  // count number of digits (should be 4)

  while (temp != 0) {
    temp /= 10;
    count++;
  }

  // for each digit, place into corresponding
  // int array index

  for (int i = count - 1; i >= 0; i--) {
    digits[i] = n % 10;
    n /= 10;
  }

  return digits;
}

int create_int_from_array(int *array) {
  // reconstruct the number

  int n = 0;

  for (int j = 0; j < 4; j++) {
    n = n * 10 + array[j];
  }

  return n;
}

int * sort_ascend(int *input_arr) {
  int temp = 0;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (input_arr[y] > input_arr[y + 1]) {
        temp = input_arr[y];
        input_arr[y] = input_arr[y + 1];
        input_arr[y + 1] = temp;
      }
    }
  }

  return input_arr;
}

int *sort_descend(int *input_arr) {
  // sort the digits in descending order

  int temp = 0;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (input_arr[y] < input_arr[y + 1]) {
        temp = input_arr[y];
        input_arr[y] = input_arr[y + 1];
        input_arr[y + 1] = temp;
      }
    }
  }

  return input_arr;
}
