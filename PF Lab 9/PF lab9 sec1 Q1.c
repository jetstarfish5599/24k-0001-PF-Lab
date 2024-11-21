// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9   section:1    Q1 
#include <stdio.h>

// Function to calculate the product
int product(int a, int b) {
    return a * b;
}
//start main
int main() {
    int num1, num2;

    // Input numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Call function 
    int result = product(num1, num2);
    printf("The product of %d and %d is %d.\n", num1, num2, result);

    return 0;
}
//end main
