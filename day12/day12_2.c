/*Q24: Write a program to calculate electricity bill based on units consumed with these rates: 
First 100 units at ₹5/unit 
Next 100 units at ₹7/unit 
Next 100 units at ₹10/unit 
Above at ₹12/unit

Sample Test Cases:
Input 1:
50
Output 1:
Bill: ₹250

Input 2:
150
Output 2:
Bill: ₹850

Input 3:
250
Output 3:
Bill: ₹1700

*/
#include <stdio.h>
int main() {
int fine;
int unit = 0;
printf("Enter units consumed:");
scanf("%d",&unit);
if (unit <=100) {
fine =  5 * unit;
printf("Fine: rupees%d\n",fine);
}
else if (unit <= 200) {
fine = 7 * unit;
printf("Fine: rupees%d\n",fine);
}
else if (unit <= 300) {
fine = 10 * unit;
printf("Fine: rupees%d\n",fine);
}
else {
fine = 12 * unit;
printf("Fine: rupees%d\n",fine);
}
return 0;
}