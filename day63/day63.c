/*🔤
Q113 (Logic Enhancers)
Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5
Explanation 1:
4th smallest element in the given array is 5.
Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7
Explanation 2:
3rd smallest element in the given array is 7.*/
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }

    printf("%d", arr[k - 1]);
    return 0;
}
