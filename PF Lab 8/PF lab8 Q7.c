// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q7
#include <stdio.h>
//start main
int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];
    int i, j, k;

    // Input the elements of the first 3x3 matrix
    printf("Enter the elements of the first 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input the elements of the second 3x3 matrix
    printf("Enter the elements of the second 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initialize the result matrix to 0
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply the two matrices
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
               //self help comment regarding mulplication matrix formula for 3*3 matrix
               // as muliplication matrix[a][b]= A[a][0]*B[0][b]+A[a][1]*B[1][b]+A[a][2]*B[2][b]
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display the result matrix
    printf("The resultant matrix after multiplication is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//end main
