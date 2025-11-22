/*🔤
Q115 (Logic Enhancers)
Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram
Explanation 1:
The strings contain the same characters with the same frequencies.
Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram
Explanation 2:
The strings do not contain the same characters.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], t[1000];
    scanf("%s %s", s, t);

    if (strlen(s) != strlen(t)) {
        printf("Not Anagram");
        return 0;
    }

    int freq[26] = {0};

    for (int i = 0; i < strlen(s); i++)
        freq[s[i] - 'a']++;

    for (int i = 0; i < strlen(t); i++)
        freq[t[i] - 'a']--;

    for (int i = 0; i < 26; i++)
        if (freq[i] != 0) {
            printf("Not Anagram");
            return 0;
        }

    printf("Anagram");
    return 0;
}
