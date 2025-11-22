/*📁
Q130 (File Handling)
Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
Input 1:
Student 1 → Name: Asha, Roll: 101, Marks: 85; Student 2 → Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92
Explanation 1:
Expected File Content (students.txt): Asha 101 85\nRavi 102 92*/
#include <stdio.h>

int main() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) return 0;

    char name1[50], name2[50];
    int roll1, roll2, marks1, marks2;

    scanf("%s %d %d", name1, &roll1, &marks1);
    scanf("%s %d %d", name2, &roll2, &marks2);

    fprintf(fp, "%s %d %d\n%s %d %d\n", name1, roll1, marks1, name2, roll2, marks2);
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) return 0;

    char name[50];
    int roll, marks;
    while (fscanf(fp, "%s %d %d", name, &roll, &marks) == 3)
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);

    fclose(fp);
    return 0;
}

