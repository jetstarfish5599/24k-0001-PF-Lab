// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q5
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element in the sparse matrix
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure to represent a sparse matrix
typedef struct {
    int rows;
    int cols;
    int nonZeroCount;
    Element* elements;
} SparseMatrix;

// Function to create a sparse matrix
SparseMatrix* createSparseMatrix(int rows, int cols, int nonZeroCount) {
    SparseMatrix* mat = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->nonZeroCount = nonZeroCount;
    mat->elements = (Element*)malloc(nonZeroCount * sizeof(Element));
    return mat;
}

// Function to input a sparse matrix
void inputSparseMatrix(SparseMatrix* mat) {
    printf("Enter row, column, and value for %d non-zero elements:\n", mat->nonZeroCount);
    for (int i = 0; i < mat->nonZeroCount; i++) {
        scanf("%d %d %d", &mat->elements[i].row, &mat->elements[i].col, &mat->elements[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(SparseMatrix* mat) {
    printf("Sparse Matrix: (row, column, value)\n");
    for (int i = 0; i < mat->nonZeroCount; i++) {
        printf("(%d, %d, %d)\n", mat->elements[i].row, mat->elements[i].col, mat->elements[i].value);
    }
}

// Function to add two sparse matrices
SparseMatrix* addSparseMatrices(SparseMatrix* mat1, SparseMatrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Matrix dimensions do not match for addition!\n");
        return NULL;
    }

    SparseMatrix* result = createSparseMatrix(mat1->rows, mat1->cols, mat1->nonZeroCount + mat2->nonZeroCount);
    int i = 0, j = 0, k = 0;

    while (i < mat1->nonZeroCount && j < mat2->nonZeroCount) {
        if (mat1->elements[i].row < mat2->elements[j].row ||
            (mat1->elements[i].row == mat2->elements[j].row && mat1->elements[i].col < mat2->elements[j].col)) {
            result->elements[k++] = mat1->elements[i++];
        } else if (mat1->elements[i].row > mat2->elements[j].row ||
                   (mat1->elements[i].row == mat2->elements[j].row && mat1->elements[i].col > mat2->elements[j].col)) {
            result->elements[k++] = mat2->elements[j++];
        } else {
            result->elements[k] = mat1->elements[i];
            result->elements[k++].value = mat1->elements[i++].value + mat2->elements[j++].value;
        }
    }

    while (i < mat1->nonZeroCount) result->elements[k++] = mat1->elements[i++];
    while (j < mat2->nonZeroCount) result->elements[k++] = mat2->elements[j++];

    result->nonZeroCount = k;
    return result;
}

// Free memory allocated for a sparse matrix
void freeSparseMatrix(SparseMatrix* mat) {
    free(mat->elements);
    free(mat);
}

// Start main
int main() {
    int rows1, cols1, nonZero1, rows2, cols2, nonZero2;

    // Input Matrix 1
    printf("Enter rows, columns, and number of non-zero elements for Matrix 1: ");
    scanf("%d %d %d", &rows1, &cols1, &nonZero1);
    SparseMatrix* mat1 = createSparseMatrix(rows1, cols1, nonZero1);
    inputSparseMatrix(mat1);

    // Input Matrix 2
    printf("Enter rows, columns, and number of non-zero elements for Matrix 2: ");
    scanf("%d %d %d", &rows2, &cols2, &nonZero2);
    SparseMatrix* mat2 = createSparseMatrix(rows2, cols2, nonZero2);
    inputSparseMatrix(mat2);

    // Display input matrices
    printf("\nMatrix 1:\n");
    displaySparseMatrix(mat1);
    printf("\nMatrix 2:\n");
    displaySparseMatrix(mat2);

    // Add matrices
    printf("\nAddition of matrices:\n");
    SparseMatrix* sum = addSparseMatrices(mat1, mat2);
    if (sum) {
        displaySparseMatrix(sum);
        freeSparseMatrix(sum);
    }

    // Clean up
    freeSparseMatrix(mat1);
    freeSparseMatrix(mat2);
    return 0;
}
//end main