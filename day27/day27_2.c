/* Q54 Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *



Sample Test Cases:
Input 1:

Output 1:
Pattern with layers of stars as shown.

*/
#include <stdio.h>

int main() {
    int i, j, space;
    int n = 4;  // number of lines in the top half

    // Upper pyramid
    for (i = 1; i <= n; i++) {
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower inverted pyramid
    for (i = n - 1; i >= 1; i--) {
        for (space = n - i; space > 0; space--) {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}