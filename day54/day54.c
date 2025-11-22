/*Q104 (Logic Enhancers)
Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
Input 1:
n = 8
Output 1:
6
Explanation 1:
6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Input 2:
n = 1
Output 2:
1
Explanation 2:
1 is the pivot integer since: 1 = 1.
Input 3:
n = 4
Output 3:
-1
Explanation 3:
It can be proved that no such integer exists.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int total = n * (n + 1) / 2;

    for (int x = 1; x <= n; x++) {
        int left = x * (x + 1) / 2;
        int right = total - (x * (x - 1) / 2);
        if (left == right) {
            printf("%d", x);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
