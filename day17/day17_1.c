/*Q33: Write a program to check if a number is an Armstrong number.

Sample Test Cases:
Input 1:
153
Output 1:
Armstrong

Input 2:
123
Output 2:
Not Armstrong

*/
#include <stdio.h>
#include <math.h>

int main() {
int num, original, rem, digits = 0;
int sum = 0;
printf("Enter a number: ");
scanf("%d", &num);
original = num;
int temp = num;
while (temp != 0) {
digits++;
temp /= 10;
}
temp = num;
while (temp != 0) {
rem = temp % 10;
sum += pow(rem, digits);
temp /= 10;
}
if (sum == original) {
printf("%d is an Armstrong number.\n", original);
} else {
printf("%d is NOT an Armstrong number.\n", original);
}
return 0;
}