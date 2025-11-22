#include <stdio.h>

int main() {
    int n, num, firstDigit, lastDigit, power = 1, swappedNum;

    printf("Enter number: ");
    scanf("%d", &n);

    num = n;  

    
    lastDigit = n % 10;

    
    while (n >= 10) {
        n = n / 10;
        power = power * 10;
    }
    firstDigit = n;

    
    if (power == 1 && firstDigit == lastDigit) {
        swappedNum = num;
    } else {
       
        int middle = num % power;    
        middle = middle / 10;        

        swappedNum = lastDigit * power + middle * 10
         + firstDigit;
    }

    printf("%d\n", swappedNum);
    return 0;
}