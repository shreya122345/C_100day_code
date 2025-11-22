/*Q5: Write a program to convert temperature from Celsius to Fahrenheit.
Sample Test Cases:
Input 1:
0
Output 1:
Fahrenheit=32

Input 2:
100
Output 2:
Fahrenheit=212

*/
#include <stdio.h>
int main() {
float cel, farh;
printf("Enter temperature in Celsius:");
scanf("%f",&cel);
farh = (cel * 9/5) + 32;
printf("Temperature in Farheneit is%.2f\n",farh);
return 0;
}