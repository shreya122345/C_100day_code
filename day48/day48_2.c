/* Q96: Reverse each word in a sentence without changing the word order.

Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    int i = 0, start = 0, end = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    while (sentence[i] != '\0') {
        
        if (sentence[i] != ' ' && sentence[i] != '\n') {
            start = i;
            
            while (sentence[i] != ' ' && sentence[i] != '\0' && sentence[i] != '\n')
                i++;
            end = i - 1;

            
            while (start < end) {
                char temp = sentence[start];
                sentence[start] = sentence[end];
                sentence[end] = temp;
                start++;
                end--;
            }
        } else {
            i++;
        }
    }

    printf("The reversed sentence is: %s\n", sentence);
    return 0;
}