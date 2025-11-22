/*📁
Q120 (File Handling)
Write a program to take a string input. Change it to sentence case.
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic
Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.
Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);

    int i = 0;
    while (s[i] == ' ') i++;

    if (s[i] != '\0')
        s[i] = toupper(s[i]);

    for (int j = i + 1; s[j] != '\0'; j++)
        s[j] = tolower(s[j]);

    printf("%s", s);
    return 0;
}
