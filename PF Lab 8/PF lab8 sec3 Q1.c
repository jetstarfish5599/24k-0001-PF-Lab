// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8 Section:3        Q1 
#include <stdio.h>

int main() {
    //initialize a 3D array with 3x3 matrices
    int array[2][3][3] = {
        {     {1, 2, 3}, {4, 5, 6},{7, 8, 9}},
        {     {10, 11, 12},  {13, 14, 15},  {16, 17, 18} }
    };

    // Variables to store the sum
    int sumPg1 = 0, sumPg2 = 0;

    // Sum all elements on the first page
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumPg1 += array[0][i][j];
        }
    }

    // Sum all elements on the second page 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumPg2 += array[1][i][j];
        }
    }

    // Print the results
    printf("Sum of elements on the first page: %d\n", sumPg1);
    printf("Sum of elements on the second page: %d\n", sumPg2);

    return 0;
}
