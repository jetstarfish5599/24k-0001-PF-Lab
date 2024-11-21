// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9   section:3   Q1
#include <stdio.h>
#include <string.h>

// Function to checkword
int wordExists(char words[][20], int rows, const char *word) {
    for (int i = 0; i < rows; i++) {
        if (strcmp(words[i], word) == 0) {
           //IF /Word found
            return 1; 
        }
    }
   // IF Word not found
    return 0; 
}
//start mainn
int main() {
    // Initialize array
    char words[5][20] = {"apple", "banana", "cherry", "date", "elderberry"};
    char inputWord[20];

    // Input a word 
    printf("Enter a word to search: ");
    scanf("%s", inputWord);

    // Check if the word exists
    if (wordExists(words, 5, inputWord)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
//end main
