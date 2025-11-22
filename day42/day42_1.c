/* Q83: Count vowels and consonants in a string.


Sample Test Cases:
Input 1:
hello
Output 1:
Vowels=2, Consonants=3

*/
#include <stdio.h>
int main()
{
    char str[100];
    char lower_case, upper_case;
    int i = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[i] != '\0')
    {
        lower_case = str[i];
        if (lower_case >= 'a' && lower_case <= 'z')
        {
            upper_case = lower_case - 32;
            printf("%c", upper_case);
        }
        else
        {
            printf("%c", lower_case);
        }
        i++;
    }
    return 0;
}