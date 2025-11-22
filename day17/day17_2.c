/*Q34 (Loops without Arrays/Strings)
Write a program to check if a number is prime.
Input 1:
7
Output 1:
Prime
Input 2:
10
Output 2:
Not prime
*/
#include <stdio.h>
int main() {
int n;
printf("enter number:");
scanf("%d", &n);
int a=0;
for (int i=2;i<=n-1;i++) {
if (n % i == 0) {
a = 1;
break;
}
}
if (a == 0)printf("number is prime\n");
else printf("it is a composite number\n");
return 0;
}