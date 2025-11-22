/*🧱
Q134 (Enum)
Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
Input 1:
FAILURE
Output 1:
Operation failed
Explanation 1:
FAILURE corresponds to a failed operation message.*/
#include <stdio.h>
#include <string.h>

int main() {
    enum Status {SUCCESS, FAILURE, TIMEOUT};
    char input[10];
    scanf("%s", input);

    enum Status s;
    if (strcmp(input, "SUCCESS") == 0) s = SUCCESS;
    else if (strcmp(input, "FAILURE") == 0) s = FAILURE;
    else s = TIMEOUT;

    if (s == SUCCESS) printf("Operation successful");
    else if (s == FAILURE) printf("Operation failed");
    else printf("Operation timed out");

    return 0;
}
