// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   section:1    Q2
#include <stdio.h>
#include <string.h>
// Reverse string function
void reverseStringRecursive(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    //call next positions
    reverseStringRecursive(str, start + 1, end - 1);
}
//start main
int main() {
    char input[100];

    // Input from user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Call the recursive function
    reverseStringRecursive(input, 0, strlen(input) - 1);

    // Display the new string
    printf("Reversed string: %s\n", input);

    return 0;
}
//ende main

