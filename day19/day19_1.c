

/* Q37: Write a program to find the LCM of two numbers.


Sample Test Cases:
Input 1:
4 5
Output 1:
20

Input 2:
7 3
Output 2:
21

*/
#include <stdio.h>

int main() {
    int a, b, lcm;
    int max; // the larger of the two numbers

    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);

    // Start checking from the maximum of the two
    max = (a > b) ? a : b;

    // Find the LCM
    while (1) {
        if (max % a == 0 && max % b == 0) {
            lcm = max;
            break;
        }
        max++;
    }

    // Output the LCM
    printf("%d\n", lcm);

    return 0;
}