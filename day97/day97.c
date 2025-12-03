/* Q147: Store employee data in a binary file using fwrite() and read using fread().


Sample Test Cases:
Input 1:
Employee details entered and stored in file.
Output 1:
Displays employee data read from file.

*/
#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

int main() {
    struct Employee emp, empRead;
    FILE *fp;

    // ---- Writing to Binary File ----
    fp = fopen("employee.bin", "wb");  // open for writing in binary
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Sample employee data
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Write structure to file
    fwrite(&emp, sizeof(struct Employee), 1, fp);

    fclose(fp);
    printf("\nEmployee details stored in binary file.\n");

    // ---- Reading from Binary File ----
    fp = fopen("employee.bin", "rb");  // open for reading in binary
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fread(&empRead, sizeof(struct Employee), 1, fp);
    fclose(fp);

    // Display read data
    printf("\nData read from file:\n");
    printf("Name: %s | ID: %d | Salary: %.2f\n",
           empRead.name,
           empRead.id,
           empRead.salary);

    return 0;
}