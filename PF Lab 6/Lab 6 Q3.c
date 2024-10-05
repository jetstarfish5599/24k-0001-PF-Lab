
// Name:Masoom Khan Roll#24k0001 Lab:6 Q3
#include <stdio.h>
//start main
int main() 
{
    //assign values to code as well as attempts to enter code
    int correct_pin = 5678;
    int user_pin;
    int attempts = 0;
    int max_attempts = 3;
//loop for 3 attempts
    while (attempts < max_attempts) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &user_pin);
//statement to check correct-pin entered by user and attempts
        if (user_pin == correct_pin) {
            printf("PIN validated successfully! Access granted.\n");
            return 0; 
            // Exit the program after successful validation
        } else {
            attempts++;
            if (attempts < max_attempts) {
                printf("Incorrect PIN. You have %d attempt(s) left.\n", max_attempts - attempts);
            }
        }
    }

    // If the user fails to enter the correct PIN after 3 attempts
    printf("Card is blocked due to too many incorrect attempts.\n");
//end of if-else
    return 0;
}
//end main
