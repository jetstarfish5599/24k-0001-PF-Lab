// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q7
#include <stdio.h>

// Define a constant for the conversion factor
#define METERS_TO_KILOMETERS 0.001
// Function to convert meters to kilometers and count calls
double convertToKilometers(double meters) {
    static int callCount = 0; // Static variable to count function calls
    callCount++;
    printf("This function has been called %d time(s).\n", callCount);
    return meters * METERS_TO_KILOMETERS;
}

//start main
int main() {
    double meters;
    int choice;

    while (1) {
        printf("\n--- Meter to Kilometer Conversion ---\n");
        printf("1. Convert meters to kilometers\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the distance in meters: ");
                scanf("%lf", &meters);
                double kilometers = convertToKilometers(meters);
                printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);
                break;
            case 2:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//end mains
