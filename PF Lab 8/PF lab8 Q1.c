// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q1 
#include <stdio.h>
//start main
int main() {
    int n;

    // Input thesquare matrix
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print diagonal elements
    printf("Main diagonal elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][i]);
    }

    // Print the second diagonal elements
    printf("\nSecondary diagonal elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", matrix[i][n - i - 1]);
    }

    return 0;
}
//end main
