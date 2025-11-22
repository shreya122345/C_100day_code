/*🧱
Q143 (Enum)
Find and print the student with the highest marks.
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)
Explanation 1:
Program compares marks of all students and prints the one with the highest.*/


#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    int n = 3;
    struct Student s[n];
    for (int i = 0; i < n; i++)
        scanf("%s %d %d", s[i].name, &s[i].roll_no, &s[i].marks);

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (s[i].marks > s[maxIndex].marks)
            maxIndex = i;

    printf("Topper: %s (Marks: %d)", s[maxIndex].name, s[maxIndex].marks);
    return 0;
}
