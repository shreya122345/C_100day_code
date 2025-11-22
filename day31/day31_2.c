/*🔢
Q62 (Arrays (1D))
Reverse an array without taking extra space.
Input 1:
4
1 2 3 4
Output 1:
4 3 2 1*/
#include <stdio.h>
int main() {
    int n, i, key, found = -1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        printf("Found at index %d\n", found);
    else
        printf("-1\n");
    return 0;
}