#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;

    // Calculate sum of digits
    while (num > 0) {
        sum += num % 10;  // Add last digit to sum
        num /= 10;        // Remove last digit
    }

    return sum;
}

int main() {
    int num, result;

    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Repeatedly sum digits until the result is a single digit
    result = num;
    while (result >= 10) {
        result = sumOfDigits(result);
    }

    // Output the result
    printf("The single-digit sum of digits is: %d\n", result);

    return 0;
}