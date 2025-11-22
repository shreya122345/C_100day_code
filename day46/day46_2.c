/* Q92: Find the first repeating lowercase alphabet in a string.

Sample Test Cases:
Input 1:
stress
Output 1:
s

*/
#include <stdio.h>
int main()
{
    char str[100];
    int i, j, found = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <='z')
        {
            for(j = 0; j < i; j++)
            {
                if(str[i] == str[j])
                {
                    found = 1;
                    break;
                }
            }
            if(!found)
            {
                printf("First repeating lowercase character: %c\n", str[i]);
                return 0;
            }
        }
        found = 0;
    }
    printf("No repeating lowercase character found.\n");
    return 0;
}