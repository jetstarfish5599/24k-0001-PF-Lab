#include <stdio.h>

int main() {
    int num;

    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Using ternary operator to check if the number is positive, negative, or zero
    (num > 0) ? printf("%d is positive.\n", num) :
    (num < 0) ? printf("%d is negative.\n", num) :
                printf("The number is zero.\n");

    return 0;
}