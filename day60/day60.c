/*🔤
Q110 (Logic Enhancers)
Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6
Explanation 1:
1st contiguous subarray , max = 3; 2nd contiguous subarray , max = 3; 3rd contiguous subarray , max = 4; 4th contiguous subarray , max = 5; 5th contiguous subarray , max = 5; 6th contiguous subarray , max = 5; 7th contiguous subarray , max = 6.
Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2
Explanation 2:
When k = 1, each element in the array is its own subarray, so the output is simply the same array.*/
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);

    if (k > n) {
        printf("-1");
        return 0;
    }

    for (int i = 0; i <= n - k; i++) {
        int max = arr[i];
        for (int j = i + 1; j < i + k; j++)
            if (arr[j] > max)
                max = arr[j];
        printf("%d", max);
        if (i != n - k) printf(" ");
    }

    return 0;
}
