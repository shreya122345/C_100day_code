/*🧱
Q144 (Enum)
Write a function that accepts a structure as parameter and prints its members.
Input 1:
Student: Neha 104 92
Output 1:
Name: Neha | Roll: 104 | Marks: 92
Explanation 1:
The structure is passed by value to a function that prints its data.*/
#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d", s.name, s.roll_no, s.marks);
}

int main() {
    struct Student s;
    scanf("%s %d %d", s.name, &s.roll_no, &s.marks);
    printStudent(s);
    return 0;
}
