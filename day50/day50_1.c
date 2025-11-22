/* Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.


Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025

*/
#include <stdio.h>

int main() {
    int d, m, y;
    char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    printf("%02d-%s-%04d\n", d, month[m - 1], y);

    return 0;
}