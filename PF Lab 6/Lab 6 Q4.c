// Name:Masoom Khan Roll#24k0001 Lab:6 Q4
#include <stdio.h>
//start main
int main() {
   // Current streak count
   int streak = 0;         
    int sent_message;       
    char choice;

    printf("Welcome to the Messaging Streak Tracker!\n");
 // start of do-while
    do {
       //ask if message sent today
         printf("\nDid you send a message today? (1 for Yes, 0 for No): ");
        scanf("%d", &sent_message);
         //start if-else
        if (sent_message == 1) {
            streak++;
            printf("Great! Your streak is now %d days.\n", streak);
        } else if (sent_message == 0) {
            streak = 0;  // Reset streak if no message was sent
            printf("Oh no! You missed a day. Your streak has been reset to 0.\n");
        } else {
            printf("Invalid input! Please enter 1 for Yes or 0 for No.\n");
        }
         //end if-else
        // Ask the user if they want to continue track for more days
        printf("\nWould you like to continue tracking the streak for the next day? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    //end do-while

    printf("\nThank you for using the Messaging Streak Tracker! Your final streak was %d days.\n", streak);

    return 0;
}
//end main