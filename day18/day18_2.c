/*Q36 (Loops without Arrays/Strings)
Write a program to find the HCF (GCD) of two numbers.
Input 1:
12 18
Output 1:
6
Input 2:
7 9
Output 2:
1
*/
#include <stdio.h>

int main() {
    int a, b, q, r;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int x = a, y = b;  

    printf("\nEuclidean steps to find HCF of %d and %d:\n", x, y);

while (b != 0) {
q = a / b;     // quotient
r = a % b;
printf("%d = %d * %d + %d\n", a, b, q, r);
a = b;
b = r;
}

    printf("\nHCF = %d\n", a);

return 0;
}