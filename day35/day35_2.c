/* Q70 Rotate an array to the right by k positions.

Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
4 5 1 2 3

*/
#include <stdio.h>
int main()
 {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k (positions to rotate): ");
    scanf("%d", &k);
    k = k % n;
    int rotated[100];
    for (int i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }
    for (int i = 0; i < n - k; i++) {
        rotated[k + i] = arr[i];
    }
    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }
    printf("\n");
    return 0;
}