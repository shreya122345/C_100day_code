/*Q2 (User Inputs, Operations & Output)
Write a program to input two numbers and display their sum, difference, product, and quotient.
Input 1:
10 2
Output 1:
Sum=12, Diff=8, Product=20, Quotient=5
Input 2:
7 3
Output 2:
Sum=10, Diff=4, Product=21, Quotient=2

*/

#include <stdio.h>

int main() {
    int a, b;
    
    // Input two numbers
    scanf("%d %d", &a, &b);

    // Perform operations and display results
    printf("Sum=%d, Diff=%d, Product=%d, Quotient=%d",
           a + b,      
           a - b,      
           a * b,      
           a / b       
    );

    return 0;
}
