/*Q84: Convert a lowercase string to uppercase without using built-in functions.


Sample Test Cases:
Input 1:
hello
Output 1:
HELLO

*/
#include <stdio.h>
int main()
{
    char str[100];
    int count_vowels = 0, count_consonants = 0, i = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[i] != '\0')
    {
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                count_vowels++;
            }
            else
            {
                count_consonants++;
            }
        }
        i++;
    }
    printf("Vowels: %d\n", count_vowels);
    printf("Consonants: %d\n", count_consonants);
    return 0;   
}