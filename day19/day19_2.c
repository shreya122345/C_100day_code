/*  Q38: Write a program to find the sum of digits of a number.


Sample Test Cases:
Input 1:
123
Output 1:
6

Input 2:
999
Output 2:
27

*/
#include <stdio.h>

int main() {
    int n, sum = 0;

    // Input number
    scanf("%d", &n);

    // Make sure n is positive (optional if negatives allowed)
    if (n < 0) {
        n = -n;
    }

    // Extract digits and add them
    while (n > 0) {
        sum += n % 10;  // get last digit
        n /= 10;        // remove last digit
    }

    // Output result
    printf("%d", sum);

    return 0;
}
