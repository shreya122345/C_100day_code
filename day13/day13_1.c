/*Q25: Write a program to implement a basic calculator using switch-case for +, -, *, /, %.

Sample Test Cases:
Input 1:
4 2 +
Output 1:
6

Input 2:
10 3 %
Output 2:
1

Input 3:
15 5 /
Output 3:
3

*/
#include <stdio.h>
int main() {
int a,b,result;
char op;
printf("enter two numbers:");
scanf("%d %d",&a,&b);
printf("enter operator:");
scanf(" %c", &op);

switch (op) {
case '+':
result = a + b;
printf("%d\n",result);
break;
case '-':
result = a - b;
printf("%d\n",result);
break;
case '*':
result = a * b;
printf("%d\n",result);
break;
case '/':
if (b !=0){
result = a / b;
printf("%d\n",result);
}
else {
printf("Division by zero not allowed");
}
break;
case '%':
if(b != 0) {
result = a % b;
printf("%d\n",result);
}
else {
printf("Modulus by zero not allowed");
}
break;

default:
printf("invalid operator");
}
return 0;
}