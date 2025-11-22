/*Q17: Write a program to find the roots of a quadratic equation and categorize them.
Sample Test Cases:
Input 1:
1 -3 2
Output 1:
Roots are real and different: 2, 1

Input 2:
1 -2 1
Output 2:
Roots are real and same: 1

Input 3:
1 2 5
Output 3:
Roots are complex

*/
#include <stdio.h>
#include <math.h>
int main() {
float a, b, c, disc, root1, root2, realPart, imaginPart;
printf("enter coeficients of numbers:");
scanf("%f %f %f", &a, &b, &c);
disc = b*b - 4* a* c;
if (disc > 0) {
root1 =(-b + sqrt(disc)) / 2 * a;
root2 = (-b + sqrt(disc)) / 2 * a;
printf("Roots are real and distinct: %.2f %.2f", root1,root2);
} 
else if(disc == 0){
root1 == root2 == -b/2*a;
printf("Roots are real and equal: %.2f %.2f", root1 , root2);
}
else {
realPart = -b/2*a;
imaginPart = sqrt(-disc)/2*a;
printf("Roots are imaginary: %.2f %.2fi and %.2f %.2fi",realPart, imaginPart,realPart,imaginPart);
}
return 0;
}