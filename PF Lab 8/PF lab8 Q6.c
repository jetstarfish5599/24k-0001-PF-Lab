// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q6
#include <stdio.h>
//start main
int main() {
    int m, n, i, j;
    
    // Input dimensions of matrix
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int matrix[m][n];
    
    // Input elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Initialize the maximum value
    int maxElement = matrix[0][0];
    int maxRow = 0, maxCol = 0;

    // Find the maximum element and its position
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Output the maximum element and its position
    printf("The maximum element is %d at position (%d, %d)\n", maxElement, maxRow, maxCol);

    return 0;
}
//end main
