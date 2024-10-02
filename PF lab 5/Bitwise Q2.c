// Name:Masoom Khan Roll#24k0001 Bitwise Q2
#include <stdio.h>

int count_ones(int n) {
    int count = 0;

    // Loop until n becomes 0
    while (n) {
        // Increment count if the last bit is 1
        count += n & 1;

        // Right shift n to check the next bit
        n >>= 1;
    }

    return count;
}

int main() {
    int num;

    // Take user input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Call the count_ones function 
    int result = count_ones(num);
//display the result   
 printf("The number of 1s in the binary representation of %d is: %d\n", num, result);

    return 0;
}