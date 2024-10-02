#include <stdio.h>

int main() {
    int num1, num2, max;

    // Input two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Find the maximum using the ternary operator
    max = (num1 > num2) ? num1 : num2;

    // Output the result
    printf("The maximum of %d and %d is %d.\n", num1, num2, max);

    return 0;
}