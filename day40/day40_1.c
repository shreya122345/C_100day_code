/*  Q79: Perform diagonal traversal of a matrix.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/
#include <stdio.h>
int main() {
    int rows, cols, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nDiagonal Traversal:\n");
    for(int k = 0; k < cols; k++) {
        i = 0;
        j = k;
        while(i < rows && j >= 0) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }
    for(int k = 1; k < rows; k++) {
        i = k;
        j = cols - 1;
        while(i < rows && j >= 0) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    return 0;
}