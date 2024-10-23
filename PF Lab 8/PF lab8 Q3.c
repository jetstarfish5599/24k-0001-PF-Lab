// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q3
#include <stdio.h>
//start main
int main() {
    int start;

    // Input number from user
    printf("Enter the starting number (odd number): ");
    scanf("%d", &start);

    // Ensure starting number is odd
    if (start % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;  
        // Exit if the number is not odd
    }

    //  loop for number of rows 
    for (int i = start; i >= 1; i -= 2) {
        // Iloop to print odd numbers in decreasing order
        for (int j = i; j >= 1; j -= 2) {
            printf("%d ", j);
        }
         // New line after each row
        printf("\n"); 
    }

    return 0;
}
//main end
