// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q2
#include <stdio.h>

// Function to swap two integgers
void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//start main
int main() {
    int num1, num2;

    // Input two integers
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Display original values
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call function
    swapIntegers(&num1, &num2);

    // Display swapped values
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
//end main
