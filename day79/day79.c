/*📁
Q129 (File Handling)
A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150
Average = 30.00
Explanation 1:
The program reads integers from the file, computes their total sum (150), and calculates the average (30.00).
*/
#include <stdio.h>

int main() {
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) return 0;

    int num, sum = 0, count = 0;
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("Sum = 0\nAverage = 0.00");
    } else {
        printf("Sum = %d\nAverage = %.2f", sum, (float)sum / count);
    }

    return 0;
}
