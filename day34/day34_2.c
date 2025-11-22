/*Q68: Delete an element from an array.

Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5

*/
#include <stdio.h>
int main() {
    int n, pos;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return 0;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}