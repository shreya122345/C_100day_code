/*📁
Q126 (File Handling)
Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)
Explanation 1:
The program opens the existing file and prints its content using fgets().
Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!
Explanation 2:
Since fopen() returns NULL, an error message is displayed instead of reading.*/
#include <stdio.h>

int main() {
    char filename[100], line[500];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!");
        return 0;
    }

    printf("File opened successfully.\n");

    while (fgets(line, sizeof(line), fp) != NULL)
        printf("%s", line);

    fclose(fp);
    return 0;
}
