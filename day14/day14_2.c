/*Q28: Write a program to print the product of even numbers from 1 to n.


Sample Test Cases:
Input 1:
4
Output 1:
8 (2 * 4)

Input 2:
6
Output 2:
48 (2 * 4 * 6)

*/
#include <stdio.h>
int main() {
    int n;
    int sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 2; i <= 2*n; i = i + 2) {
        sum += i;   
    }

    printf("Sum of first %d even numbers: %d\n", n, sum);

return 0;
}