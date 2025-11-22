/* Q67: Insert an element in an array at a given position.

Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40

*/
#include <stdio.h>
int main()
 {
    int n, pos, key;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position and element to insert: ");
    scanf("%d %d", &pos, &key);
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = key;
    n++;
        printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}