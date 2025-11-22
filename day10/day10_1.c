/*Q19: Write a program to classify a triangle as Equilateral, Isosceles, or Scalene based on its side lengths.


Sample Test Cases:
Input 1:
3 3 3
Output 1:
Equilateral

Input 2:
3 3 4
Output 2:
Isosceles

Input 3:
2 3 4
Output 3:
Scalene

*/
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("The triangle is Equilateral\n");
        }
        else if (a == b || b == c || a == c) {
            printf("The triangle is Isosceles\n");
        }
        else {
            printf("The triangle is Scalene\n");
        }
    } else {
        printf("Invalid triangle\n");
    }

    return 0;
}