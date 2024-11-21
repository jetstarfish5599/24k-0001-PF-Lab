// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9   section:2    Q1
#include <stdio.h>
#include <string.h>

// Function to append first n characters 
void appendCharacters(char *dest, const char *src, int n) {
    strncat(dest, src, n);
}
//start main
int main() {
    char dest[100], src[100];
    int n;

    // Input destination
    printf("Enter the destination string: ");
    fgets(dest, sizeof(dest), stdin);
    // Remove newline character
    dest[strcspn(dest, "\n")] = '\0'; 

    // Input source string
    printf("Enter the source string: ");
    fgets(src, sizeof(src), stdin);
   // Remove newline character
    src[strcspn(src, "\n")] = '\0'; 

    // Input characters to append
    printf("Enter the number of characters to append: ");
    scanf("%d", &n);

    // Append first n characters
    appendNCharacters(dest, src, n);

    // Print the concatenated string
    printf("The concatenated string is: %s\n", dest);

    return 0;
}
//end main
