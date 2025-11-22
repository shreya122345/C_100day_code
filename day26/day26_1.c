/*Q51 Write a program to print the following pattern:
    5
   45
  345
 2345
12345

Sample Test Cases:
Input 1:

Output 1:
    5
   45
  345
 2345
12345

*/
#include <stdio.h>

int main() {
    int i, j, space;

    for (i = 5; i >= 1; i--) {                 // outer loop controls rows
        for (space = 1; space < i; space++) {  // print leading spaces
            printf(" ");
        }
        for (j = i; j <= 5; j++) {             // print numbers from i to 5
            printf("%d", j);
        }
        printf("\n");                          // move to next line
    }

    return 0;
}