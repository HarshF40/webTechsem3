// Implement a C program to convert a Hexidecimal, octal and binary number to decimal and vice versa

#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main() {
  char hex_value[20];
  // Take the hex value
  printf("Enter Hex Value: ");
  scanf("%s", hex_value);
  printf("\nEntered Hex Value: %s", hex_value);

  // Convert the number to lowercase
  for(int i = 0; hex_value[i]!='\0'; i++) hex_value[i] = tolower(hex_value[i]);
  printf("\nLowered Hex Value: %s", hex_value);

  // Converting the number to decimal
  int integer = 0;
  int i = 0;

  // Getting the length of string 
  for(; hex_value[i] != '\0'; i++);
  printf("\nSize of number(str): %d", i);

  ///////////////////////////

  int j = 0;
  i -= 1;
  int k = 3;
  printf("%d", i);
  while(i > -1) {
    printf("\n%c", hex_value[i]);
    if(hex_value[i] > 96 && hex_value[i] < 103) {
      integer += (hex_value[i] + k)/10*(pow(16, j));
    } else if(hex_value[i] > 48 && hex_value[i] < 58) {
      integer += (hex_value[i] - 48)*pow(16, j);
    }
    printf("%d", integer);
    i--;
    j++;
    k+=9;
  }

  printf("\nConverted Number: %d", integer);

  return 0;
}
