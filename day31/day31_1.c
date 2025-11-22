/*Q61 (Arrays (1D))
Search for an element in an array using linear search.
Input 1:
5
1 2 3 4 5
3
Output 1:
Found at index 2
Input 2:
4
10 20 30 40
25
Output 2:
-1
*/

#include <stdio.h>
int main() {
    int n, i;
    int pos = 0, neg = 0, ze = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            pos++;
        else if (arr[i] < 0)
            neg++;
        else
            ze++;
    }
    printf("Positive=%d, Negative=%d, Zero=%d\n", pos, neg, ze);
    return 0;
}