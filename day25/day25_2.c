/*Q50 Write a program to print the following pattern:
*****
 ****
  ***
   **
    *

Sample Test Cases:
Input 1:

Output 1:
*****
 ****
  ***
   **
    *

Input 2:

Output 2:
Note: Spaces indicate indentation.

*/
#include <stdio.h>

int main() {
    int i, j, space;

    for (i = 5; i >= 1; i--) {            // outer loop → rows
        for (space = 5; space > i; space--) {  // print leading spaces
            printf(" ");
        }
        for (j = 1; j <= i; j++) {        // print stars
            printf("*");
        }
        printf("\n");                     // move to next line
    }

    return 0;
}