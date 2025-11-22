/* Q43 Write a program to check if a number is a strong number.

Sample Test Cases:
Input 1:
145
Output 1:
Strong number

Input 2:
123
Output 2:
Not strong number

*/
#include <stdio.h>

int main() {
    int n, num, digit, sum = 0, fact, i;

    printf("Enter number: ");
    scanf("%d", &n);

    num = n;  // keep a copy

    while (n > 0) {
        digit = n % 10;   // extract last digit

        // find factorial of digit
        fact = 1;
        for (i = 1; i <= digit; i++) {
            fact *= i;
        }

        sum += fact;  // add factorial to sum
        n /= 10;      // remove last digit
    }

    if (sum == num)
        printf("Strong number\n");
    else
        printf("Not strong number\n");

    return 0;
}