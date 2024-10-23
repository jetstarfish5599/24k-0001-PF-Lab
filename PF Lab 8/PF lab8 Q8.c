// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q8
#include <stdio.h>

int main() {
    int n, i, j, space;

    // Input number of rows for upper half of  diamond
    printf("Enter the number of rows for the upper half of the diamond: ");
    scanf("%d", &n);

    // Upper half of the diamond
    for (i = 1; i <= n; i++) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the diamond
    for (i = n - 1; i >= 1; i--) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
