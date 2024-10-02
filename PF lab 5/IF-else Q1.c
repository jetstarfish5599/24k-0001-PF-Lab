#include <stdio.h>

int main() {
    int age;

    // Ask the user for their age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Categorize age using nested if-else statements
    if (age >= 0) {
        if (age <= 12) {
            printf("You are a Child.\n");
        } else if (age <= 19) {
            printf("You are a Teenager.\n");
        } else if (age <= 59) {
            printf("You are an Adult.\n");
        } else {
            printf("You are a Senior.\n");
        }
    } else {
        printf("Invalid age entered.\n");
    }

    return 0;
}