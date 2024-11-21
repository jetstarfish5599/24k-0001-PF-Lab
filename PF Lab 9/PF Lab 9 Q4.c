// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q4
#include <stdio.h>

// Function name
float calculate(float num1, float num2, char operation);
float calculate(float num1, float num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                // for  division by zero error
                return 0;
            }
        default:
            printf("Invalid operation!\n");
            return 0.0;
    }
}
int main() {
    float num1, num2, result;
    char operation;

    // Input from the user
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Call function
    result = calculate(num1, num2, operation);

    // Display the result
    if (operation == '/' && num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2f\n", result);
    }

    return 0;
}
//end main
// Function definition
