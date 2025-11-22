/*Q3 (User Inputs, Operations & Output)
Write a program to calculate the area and perimeter of a rectangle given its length and breadth.
Input 1:
5 10
Output 1:
Area=50, Perimeter=30
Input 2:
3 7
Output 2:
Area=21, Perimeter=20
*/
#include <stdio.h>

int main() {
    float length, breadth;

    // Input length and breadth
    scanf("%f %f", &length, &breadth);

    // Calculate area and perimeter
    float area = length * breadth;
    float perimeter = 2 * (length + breadth);

    // Output results
    printf("Area=%.2f, Perimeter=%.2f", area, perimeter);

    return 0;
}
