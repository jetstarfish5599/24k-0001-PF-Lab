// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q5
// C program to illustrate Saddle point
#include <stdio.h>
#include <stdbool.h>

// Function to find saddle point
bool findSaddlePoint(int mat[3][3], int n)
{
    // Process all rows one by one
    for (int i = 0; i < n; i++)
    {
        // Find the minimum element of row i.
        // find column index of the minimum element
        int min_row = mat[i][0], col_ind = 0;
        for (int j = 1; j < n; j++)
        {
            if (min_row > mat[i][j])
            {
                min_row = mat[i][j];
                col_ind = j;
            }
        }
 
        // Check minimum element of row
        // Check maximum element of column
        int k;
        for (k = 0; k < n; k++)
 
           
            if (min_row < mat[k][col_ind])
                break;
 
        // print saddle point if present in this row
  
        if (k == n)
        {
           printf("Value of Saddle Point %d",min_row);
           return true;
        }
    }
 
    // If Saddle Point not found
    return false;
}
 
// start main
int main()
{
    int mat[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int n = 3;
    if (findSaddlePoint(mat, n) == false)
       printf("No Saddle Point ");
    return 0;
}
//end  main
