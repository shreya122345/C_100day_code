/*🔤
Q106 (Logic Enhancers)
Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.

N.B:
- Print the output for each element in a comma separated fashion.
- Do not use Stack, use brute force approach (nested loop) to solve.
Input 1:
arr = [1, 3, 2, 4]
Output 1:
3, 4, 4, -1
Explanation 1:
The next larger element to 1 is 3, for 3 it is 4, for 2 it is 4 and for 4 there is no next greater element so it is -1.
Input 2:
arr = [6, 8, 0, 1, 3]
Output 2:
8, -1, 1, 3, -1
Explanation 2:
Next greater element for 6 is 8, for 8 it is -1, for 0 it is 1, for 1 it is 3 and for 3 there is no greater element on right hence -1.
Input 3:
arr = [1, 2, 3, 5]
Output 3:
2, 3, 5, -1
Explanation 3:
In a sorted array, each element’s next greater is its immediate next element except for the last element which has none, so -1.
Input 4:
arr = [5, 4, 3, 1]
Output 4:
-1, -1, -1, -1
Explanation 4:
No element has a greater element on its right, so all next greater elements are -1.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        int next = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break;
            }
        }
        printf("%d", next);
        if (i != n - 1) printf(",");
    }

    return 0;
}
