/*Q27: Write a program to print the sum of the first n odd numbers.


Sample Test Cases:
Input 1:
3
Output 1:
9

Input 2:
5
Output 2:
25

*/
#include <stdio.h>
int main () {
int n;
int sum = 0;
printf("enter n:");
scanf("%d", &n);
for(int i=1;i<=2*n;i=i+2) {
sum = i+1;
}
printf("sum of %d odd numbers:%d\n", n, sum);
return 0;
}