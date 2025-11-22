/* Q93: Check if two strings are anagrams of each other.

Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int i, freq[26] = {0};
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    if(strlen(str1) != strlen(str2)) {
        printf("Strings are not anagrams.\n");
        return 0;
    }
    for(i = 0; str1[i] != '\0'; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z')
            freq[str1[i] - 'a']++;
        else if(str1[i] >= 'A' && str1[i] <= 'Z')
            freq[str1[i] - 'A']++;
    }
    for(i = 0; str2[i] != '\0'; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z')
            freq[str2[i] - 'a']--;
        else if(str2[i] >= 'A' && str2[i] <= 'Z')
            freq[str2[i] - 'A']--;
    }
    for(i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }
    printf("Strings are anagrams.\n");
    return 0;
}