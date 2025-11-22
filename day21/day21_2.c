/*  Q42 Write a program to check if a number is a perfect number.

Sample Test Cases:
Input 1:
6
Output 1:
Perfect number

Input 2:
10
Output 2:
Not perfect number

*/
#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    // Find sum of all proper divisors
    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // Check if sum equals the number
    if (sum == n)
        printf("Perfect number\n");
    else
        printf("Not perfect number\n");

    return 0;
}