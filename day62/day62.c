/*🔤
Q112 (Logic Enhancers)
Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11
Explanation 1:
The subarray [7, -1, 2, 3] has the largest sum 11.
Input 2:
arr[] = [-2, -4]
Output 2:
-2
Explanation 2:
The subarray [-2] has the largest sum -2.
Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25
Explanation 3:
The subarray has the largest sum 25.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxSoFar = arr[0], curr = arr[0];

    for (int i = 1; i < n; i++) {
        if (curr + arr[i] > arr[i])
            curr = curr + arr[i];
        else
            curr = arr[i];

        if (curr > maxSoFar)
            maxSoFar = curr;
    }

    printf("%d", maxSoFar);
    return 0;
}
