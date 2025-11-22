/*Q18: Write a program to assign grades based on a percentage input.


Sample Test Cases:
Input 1:
95
Output 1:
Grade A

Input 2:
82
Output 2:
Grade B

Input 3:
68
Output 3:
Grade D

Input 4:
50
Output 4:
Grade F

*/
#include <stdio.h>
int main() {
int percentage;
printf("enter percentage:");
scanf("%d", &percentage);
if (percentage >=90 && percentage <= 100){
printf("Grade:A");
}
else if(percentage >= 75) {
printf("Grade:B");
}
else if(percentage >= 50) {
printf("Grade:C");
}
else if(percentage >= 35) {
printf("Grade:D");
}
else if (percentage >= 0) {
printf("Failed");
} 
else {
printf("invalid percentage");
}
return 0;
}