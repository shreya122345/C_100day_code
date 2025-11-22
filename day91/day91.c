/*🧱
Q141 (Enum)
Define a structure Student with name, roll_no, and marks, then read and print one student's data.
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90
Explanation 1:
The program stores and displays one student's details using structure members.
*/
#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student s;
    scanf("%s %d %d", s.name, &s.roll_no, &s.marks);
    printf("Name: %s | Roll: %d | Marks: %d", s.name, s.roll_no, s.marks);
    return 0;
}
