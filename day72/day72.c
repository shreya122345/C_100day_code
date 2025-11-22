/*📁
Q122 (File Handling)
Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
Input 1:
File: info.txt (Content: Name: Rahul\nAge: 23)
Output 1:
Name: Rahul
Age: 23
Explanation 1:
The program reads each line from info.txt using fgets() and prints it until EOF.*/
#include <stdio.h>

int main() {
    char line[500];
    FILE *fp = fopen("info.txt", "r");

    if (fp == NULL) {
        printf("File not found");
        return 0;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
        printf("%s", line);

    fclose(fp);
    return 0;
}
