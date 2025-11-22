/* Q64: Find the digit that occurs the most times in an integer number.

Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7

*/
#include <stdio.h>
int main()
 {
    long long n;
    int freq[10] = {0};
    int digit, maxFreq = 0, mostFreqDigit = 0;
    printf("Enter an integer: ");
    scanf("%lld", &n);
    if (n < 0) n = -n;
    while (n > 0) {
        digit = n % 10;
        freq[digit]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFreqDigit = i;
        }
    }
    printf("%d\n", mostFreqDigit);
    return 0;
}