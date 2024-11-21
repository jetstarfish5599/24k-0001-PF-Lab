// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q1
#include <stdio.h>
#include <string.h>

// Function to check palindrome
int isPalindrome(const char *word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
     // Not a palindrome     
            return 0; 
        }
    }
    // Is a palindrome
    return 1; 
}
//start main
int main() {
    char words[5][20];
    int i;

    // Input 5 words
    printf("Enter 5 words (each with a max length of 20 characters):\n");
    for (i = 0; i < 5; i++) {
        scanf("%s", words[i]);
    }

    // Check word is a palindrome
    printf("\nResults:\n");
    for (i = 0; i < 5; i++) {
        if (isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }

    return 0;
}
//end main
