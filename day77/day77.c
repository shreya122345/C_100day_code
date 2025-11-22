/*📁
Q127 (File Handling)
Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING
Explanation 1:
All lowercase letters in input.txt are converted to uppercase using character manipulation before writing to output.txt.*/
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) return 0;

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) return 0;

    int c;
    while ((c = fgetc(in)) != EOF) {
        if (islower(c)) c = toupper(c);
        fputc(c, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}
