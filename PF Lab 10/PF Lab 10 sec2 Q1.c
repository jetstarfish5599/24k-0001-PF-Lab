// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   section:2    Q1
#include <stdio.h>
#include <string.h>

// Define the structure for flight information
typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
} Flight;

// Function prototypes
void bookSeat(Flight flights[], int flightCount, int flightNumber);
void displayFlights(Flight flights[], int flightCount);
//start main
int main() {
    // Array of flights
    Flight flights[] = {
        {101, "Karachi", "Lahore", "1/12/2024", 50},
        {102, "Islamabad", "Karachi", "2/12/2024", 30},
        {103, "Lahore", "Quetta", "3/12/2024", 20},
        {104, "Karachi", "Dubai", "4/12/2024", 40},
        {105, "Peshawar", "Karachi", "5/12/2024", 25}
    };
    int flightCount = sizeof(flights) / sizeof(flights[0]);
    int choice, flightNumber;

    while (1) {
        printf("\n--- Flight Management System ---\n");
        printf("1. Display Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights(flights, flightCount);
                break;
            case 2:
                printf("Enter the flight number to book a seat: ");
                scanf("%d", &flightNumber);
                bookSeat(flights, flightCount, flightNumber);
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
//ENd main

// Function to display flights
void displayFlights(Flight flights[], int flightCount) {
    printf("\nFlights within Pakistan:\n");
    printf("Flight No. | Departure   | Destination | Date       | Seats Available\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, "Dubai") != 0 &&
            strcmp(flights[i].destinationCity, "Dubai") != 0) {
            printf("%-10d | %-11s | %-11s | %-10s | %-15d\n",
                   flights[i].flightNumber,
                   flights[i].departureCity,
                   flights[i].destinationCity,
                   flights[i].date,
                   flights[i].availableSeats);
        }
    }
}
//end display flight function
// Function to book a seat on a flight
void bookSeat(Flight flights[], int flightCount, int flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully on flight %d.\n", flightNumber);
            } else {
                printf("No seats available on flight %d.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight number %d not found.\n", flightNumber);
}
//end book flight function