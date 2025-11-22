/*Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.

Sample Test Cases:
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5

Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76

*/
#include <stdio.h>
#include <math.h>
int main()
{
float A, P, R, T, CI, SI;
printf("Enter principal , interest and time:");
scanf("%f %f %f", &P, &R, &T);
SI = (P * R * T)/100;
A = P * pow ((1 + R/100),T);
CI = A - P;
printf("Simple interest=% .2f\n", SI);
printf("Compound interest=% .2f\n",CI);
return 0;
}