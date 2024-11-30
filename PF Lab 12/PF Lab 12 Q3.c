// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q1
#include <stdio.h>

// Function to find the length of a string using pointers
int stringLength(char *str) {
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    return length;
}

// Function to reverse a string using pointers
void reverseString(char *str) {
    char *start = str;
    char *end = str + stringLength(str) - 1;  // Point to the last character
    char temp;

    while (start < end) {
        // Swap the characters
        temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers
        start++;
        end--;
    }
}

// Function to concatenate two strings using pointers
void concatenateStrings(char *str1, char *str2) {
    char *ptr1 = str1 + stringLength(str1);  // Point to the end of str1
    char *ptr2 = str2;

    while (*ptr2 != '\0') {
        *ptr1 = *ptr2;  // Copy character from str2 to str1
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';  // Add null terminator at the end
}
//start main
int main() {
    char str1[100], str2[100], str3[100];

    // Input a string to find its length
    printf("Enter a string to find its length: ");
    scanf("%s", str1);
    printf("Length of '%s': %d\n", str1, stringLength(str1));

    // Input a string to reverse
    printf("Enter a string to reverse: ");
    scanf("%s", str2);
    reverseString(str2);
    printf("Reversed string: %s\n", str2);

    // Input strings to concatenate
    printf("Enter the first string for concatenation: ");
    scanf("%s", str1);
    printf("Enter the second string for concatenation: ");
    scanf("%s", str3);
    concatenateStrings(str1, str3);
    printf("Concatenated string: %s\n", str1);

    return 0;
}
//end main