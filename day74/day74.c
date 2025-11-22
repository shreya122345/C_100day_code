/*📁
Q124 (File Handling)
Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt
Explanation 1:
Expected File (destination.txt): Learning C File Handling*/
#include <stdio.h>

int main() {
    char src[100], dest[100];
    scanf("%s %s", src, dest);

    FILE *fs = fopen(src, "r");
    if (fs == NULL) return 0;

    FILE *fd = fopen(dest, "w");
    if (fd == NULL) return 0;

    int ch;
    while ((ch = fgetc(fs)) != EOF)
        fputc(ch, fd);

    fclose(fs);
    fclose(fd);
    return 0;
}
