/* Q100: Print all sub-strings of a string.

Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c

*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    char all_substr[500];
    int i, j, k = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  

    for (i = 0; str[i] != '\0'; i++) {
        for (j = i; str[j] != '\0'; j++) {
            
            for (k = 0; k < j - i + 1; k++) {
                all_substr[k] = str[i + k];
            }
            all_substr[k] = '\0';  
            printf("Substring: %s\n", all_substr);
        }
    }

    return 0;
}