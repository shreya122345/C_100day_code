/*🔤
Q114 (Logic Enhancers)
Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
Input 1:
s = "abcabcbb"
Output 1:
3
Explanation 1:
The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Input 2:
s = "bbbbb"
Output 2:
1
Explanation 2:
The answer is "b", with the length of 1.
Input 3:
s = "pwwkew"
Output 3:
3
Explanation 3:
The answer is "wke", with the length of 3. Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    int last[256];
    for (int i = 0; i < 256; i++) last[i] = -1;

    int start = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (last[(unsigned char)s[i]] >= start)
            start = last[(unsigned char)s[i]] + 1;

        last[(unsigned char)s[i]] = i;

        if (i - start + 1 > maxLen)
            maxLen = i - start + 1;
    }

    printf("%d", maxLen);
    return 0;
}
