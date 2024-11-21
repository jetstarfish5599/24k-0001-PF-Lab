// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q5
#include <stdio.h>
#include <string.h>

// Function prototype
void reverseString(char str[]);

// Function definition
void reverseString(char str[]) {
    int start = 0, end = strlen(str) - 1;
    char temp;

    // Swap characters towards the middle
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
//start main
int main() {
    char input[100];

    // Input fromuser
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Removecharacter if present
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Call function
    reverseString(input);

    // Display the reversed string
    printf("Reversed string: %s\n", input);

    return 0;
}
//end main

