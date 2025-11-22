/*📁
Q125 (File Handling)
Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.
Explanation 1:
Output File (data.txt after execution): Hello world\nThis is appended text.
*/
#include <stdio.h>

int main() {
    char filename[100], text[500];
    scanf("%s", filename);
    getchar();
    fgets(text, sizeof(text), stdin);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("File not found");
        return 0;
    }

    fputs(text, fp);
    fclose(fp);

    printf("File updated successfully with appended text.");
    return 0;
}
