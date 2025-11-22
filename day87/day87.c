/*🧱
Q137 (Enum)
Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
Input 1:
GUEST
Output 1:
Welcome Guest!
Explanation 1:
Enum value determines which message is displayed.

*/
#include <stdio.h>
#include <string.h>

int main() {
    enum Role {ADMIN, USER, GUEST};
    char input[10];
    scanf("%s", input);

    enum Role r;
    if (strcmp(input, "ADMIN") == 0) r = ADMIN;
    else if (strcmp(input, "USER") == 0) r = USER;
    else r = GUEST;

    if (r == ADMIN) printf("Welcome Admin!");
    else if (r == USER) printf("Welcome User!");
    else printf("Welcome Guest!");

    return 0;
}
