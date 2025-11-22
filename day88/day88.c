/*🧱
Q138 (Enum)
Print all enum names and integer values using a loop.
Input 1:
No input
Output 1:
RED=0
YELLOW=1
GREEN=2
Explanation 1:
Iterating through enum values prints each constant with its assigned integer.*/
#include <stdio.h>

int main() {
    enum Colors {RED, YELLOW, GREEN};
    const char* names[] = {"RED", "YELLOW", "GREEN"};

    for (int i = 0; i <= GREEN; i++)
        printf("%s=%d\n", names[i], i);

    return 0;
}
