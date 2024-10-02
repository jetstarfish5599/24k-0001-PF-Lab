// Name:Masoom Khan Roll#24k0001 Problem Q4
#include <stdio.h>
//start main
int main() {
    int age;
    float income;
    int credit_score;

    // Take user input for age, income, and credit score respectively
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your annual income (in dollars): ");
    scanf("%f", &income);

    printf("Enter your credit score: ");
    scanf("%d", &credit_score);

    // Check eligibility using logical AND operator (&&)
    if (age >= 18 && income >= 20000 && credit_score >= 500) {
        printf("You are eligible for the loan.\n");
    } else {
        printf("You are not eligible for the loan.\n");
    }

    return 0;
}