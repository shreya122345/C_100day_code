/*📁
Q128 (File Handling)
Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8
Consonants: 10
Explanation 1:
The program iterates through each character, counts vowels (A, E, I, O, U) and consonants, ignoring other symbols.*/
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) return 0;

    int vowels = 0, consonants = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            char ch = tolower(c);
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vowels++;
            else
                consonants++;
        }
    }

    fclose(fp);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d", consonants);

    return 0;
}
