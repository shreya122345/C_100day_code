/*Q32 (Loops without Arrays/Strings)
Write a program to check if a number is a palindrome.
Input 1:
121
Output 1:
Palindrome
Input 2:
123
Output 2:
Not palindrome*/
#include <stdio.h>

int main() {
int original, num, rev = 0, rem;
printf("Enter a number: ");
scanf("%d", &num);
original = num;
while (num != 0) {
rem = num % 10;
rev = rev * 10 + rem;
num = num / 10;
}
if (original == rev) {
printf("It is a palindrome number");
}
else {
printf("It is not a palindrome number");
}
return 0;
}