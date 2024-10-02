#include <stdio.h>

int main() {
    int age;
    char citizen;

    // Input age from the user
    printf("Enter your age: ");
    scanf("%d", &age);

    // Input citizenship status from the user
    // 'Y' for Yes (citizen) and 'N' for No (not a citizen)
    printf("Are you a citizen? (Y/N): ");
    scanf(" %c", &citizen);

    // Check if the person is eligible to vote
    if (age >= 18 && (citizen == 'Y' || citizen == 'y')) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote.\n");
    }

    return 0;
}