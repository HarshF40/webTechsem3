// Implement a C program to convert a Hexidecimal, octal and binary number to decimal and vice versa

#include <stdio.h>
#include <math.h>

int to_bin(int);
int to_dec(int);
float float_bin_to_dec(float);

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("Number %d in binary: %d\n", num, to_bin(num));
  printf("The same number to dec again by function: %d\n", to_dec(to_bin(num)));
  return 0;
}

int to_bin(int num) {
  int temp = num;
  int remainder = 0;
  int bin = 0;
  int place=1;

  while(temp!=0){
    remainder = temp%2;
    temp /= 2;
    bin += place * remainder;
    place*=10;
  }
  return bin;
}

int to_dec(int num){
  int temp = num;
  int dec = 0;
  int remainder = 0;
  int power = 0;

  while(temp!=0){
    remainder = temp % 10;
    dec += powf(2, power)*remainder;
    power+=1;
    temp /= 10; 
  } 
  return dec;
}

float float_bin_to_dec(float num) {

}
