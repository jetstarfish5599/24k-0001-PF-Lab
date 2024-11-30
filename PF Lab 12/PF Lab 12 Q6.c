// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 1024
#define WORD_MAX_LENGTH 100

// Structure for storing words and their frequencies
typedef struct {
    char* word;
    int frequency;
} WordFrequency;

// Function to resize the word frequency array dynamically
WordFrequency* resizeWordFrequencyArray(WordFrequency* array, int* capacity) {
    *capacity *= 2;
    return (WordFrequency*)realloc(array, (*capacity) * sizeof(WordFrequency));
}

// Function to find a word in the word frequency array
int findWord(WordFrequency* wordFreqArray, int size, const char* word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordFreqArray[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to clean a word (remove punctuation and convert to lowercase)
void cleanWord(char* word) {
    char* src = word;
    char* dest = word;
    while (*src) {
        if (isalpha((unsigned char)*src) || isdigit((unsigned char)*src)) {
            *dest++ = tolower((unsigned char)*src);
        }
        src++;
    }
    *dest = '\0';
}
//star main
int main() {
    // Open the file
    FILE* file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: Enable to open file.\n");
        return 1;
    }

    // Dynamically allocate memiry 
    char* buffer = (char*)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
    if (!buffer) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    int bufferSize = INITIAL_BUFFER_SIZE;
    int bytesRead = 0;
    int c;

    // Read the file dynamically into the buffer
    while ((c = fgetc(file)) != EOF) {
        if (bytesRead == bufferSize) {
            bufferSize *= 2;
            buffer = (char*)realloc(buffer, bufferSize * sizeof(char));
            if (!buffer) {
                printf("Error: Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
        }
        buffer[bytesRead++] = (char)c;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the buffar

    fclose(file);

    // Process the buffer to count word frequencies
    WordFrequency* wordFreqArray = (WordFrequency*)malloc(10 * sizeof(WordFrequency));
    int capacity = 10, size = 0;

    char* token = strtok(buffer, " \n\t");
    while (token) {
        cleanWord(token);

        if (strlen(token) > 0) {
            int index = findWord(wordFreqArray, size, token);
            if (index != -1) {
                wordFreqArray[index].frequency++;
            } else {
                if (size == capacity) {
                    wordFreqArray = resizeWordFrequencyArray(wordFreqArray, &capacity);
                }
                wordFreqArray[size].word = strdup(token);
                wordFreqArray[size].frequency = 1;
                size++;
            }
        }
        token = strtok(NULL, " \n\t");
    }

    // Print word freqeuncies
    printf("Word Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordFreqArray[i].word, wordFreqArray[i].frequency);
        free(wordFreqArray[i].word);
    }

    // Free allocated memory
    free(wordFreqArray);
    free(buffer);

    return 0;
}