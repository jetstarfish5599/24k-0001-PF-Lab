// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q6
#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

// Define a structure for travel packages
typedef struct {
    char packageName[50];
    char destination[50];
    int duration;      // in days
    float cost;        // cost in PKR
    int seatsAvailable;
} TravelPackage;

// Function prototypes
void displayPackages(TravelPackage packages[], int count);
void bookPackage(TravelPackage packages[], int count);
//start main
int main() {
    TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    // Predefined packages
    strcpy(packages[0].packageName, "Northern Adventure");
    strcpy(packages[0].destination, "Hunza");
    packages[0].duration = 7;
    packages[0].cost = 45000.00;
    packages[0].seatsAvailable = 10;

    strcpy(packages[1].packageName, "Beach Retreat");
    strcpy(packages[1].destination, "Gwadar");
    packages[1].duration = 5;
    packages[1].cost = 30000.00;
    packages[1].seatsAvailable = 15;

    strcpy(packages[2].packageName, "Cultural Heritage");
    strcpy(packages[2].destination, "Lahore");
    packages[2].duration = 3;
    packages[2].cost = 20000.00;
    packages[2].seatsAvailable = 20;

    packageCount = 3;

    while (1) {
        printf("\n--- Travel Package Management System ---\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//end main
// Function to display available travel packages
void displayPackages(TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("\n--- Available Travel Packages ---\n");
    for (int i = 0; i < count; i++) {
        printf("Package %d:\n", i + 1);
        printf("Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: PKR %.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
        printf("-------------------------------\n");
    }
}
//end display packages
// Function to book a travel package
void bookPackage(TravelPackage packages[], int count) {
    int packageIndex, seats;

    if (count == 0) {
        printf("No packages available to book.\n");
        return;
    }

    // Display available packages
    displayPackages(packages, count);

    // Input package to book
    printf("Enter the package number to book: ");
    scanf("%d", &packageIndex);

    if (packageIndex < 1 || packageIndex > count) {
        printf("Invalid package number!\n");
        return;
    }

    // Input number of seats to book
    printf("Enter the number of seats to book: ");
    scanf("%d", &seats);

    if (seats <= 0 || seats > packages[packageIndex - 1].seatsAvailable) {
        printf("Invalid number of seats! Only %d seats are available.\n",
               packages[packageIndex - 1].seatsAvailable);
        return;
    }

    // Update seats available
    packages[packageIndex - 1].seatsAvailable -= seats;
    printf("Booking successful! You have booked %d seats for the '%s' package.\n",
           seats, packages[packageIndex - 1].packageName);
}
//end book package