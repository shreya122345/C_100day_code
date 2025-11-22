/*🧱
Q139 (Enum)
Show that enums store integers by printing assigned values.
Input 1:
No input
Output 1:
SUCCESS=0, FAILURE=1, TIMEOUT=2
Explanation 1:
Enum constants are internally stored as integer values starting from 0.
*/
#include <stdio.h>

int main() {
    enum Status {SUCCESS, FAILURE, TIMEOUT};
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d", SUCCESS, FAILURE, TIMEOUT);
    return 0;
}
