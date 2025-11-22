/* Q85: Reverse a string.


Sample Test Cases:
Input 1:
abcd
Output 1:
dcba

*/
#include <stdio.h>
int main() {
    char str[100];
    char rev_str[100];
    int i = 0, j = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[i] != '\0')
    {
        i++;
    }
    for (j = 0; j < i; j++)
    {
        rev_str[j] = str[i - j - 1];
    }
    rev_str[j] = '\0';
    printf("Reversed string: %s\n", rev_str);
    return 0;
}