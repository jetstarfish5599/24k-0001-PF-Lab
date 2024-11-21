// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q4
#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

// Define a structure to store car details
typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
} Car;

// Function prototypes
void addCar(Car cars[], int *count);
void displayCars(Car cars[], int count);
void searchCarByMakeOrModel(Car cars[], int count, const char *keyword);
//start main
int main() {
    Car cars[MAX_CARS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Car Dealership Management System ---\n");
        printf("1. Add New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &count);
                break;
            case 2:
                displayCars(cars, count);
                break;
            case 3: {
                char keyword[50];
                printf("Enter make or model to search: ");
                getchar(); // Clear newline character
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = '\0';
                searchCarByMakeOrModel(cars, count, keyword);
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//end main
// Function to add a new car
void addCar(Car cars[], int *count) {
    if (*count >= MAX_CARS) {
        printf("Maximum car limit reached!\n");
        return;
    }

    printf("Enter car make: ");
    getchar(); 
    fgets(cars[*count].make, sizeof(cars[*count].make), stdin);
    cars[*count].make[strcspn(cars[*count].make, "\n")] = '\0'; 

    printf("Enter car model: ");
    fgets(cars[*count].model, sizeof(cars[*count].model), stdin);
    cars[*count].model[strcspn(cars[*count].model, "\n")] = '\0';

    printf("Enter car year: ");
    scanf("%d", &cars[*count].year);

    printf("Enter car price: ");
    scanf("%f", &cars[*count].price);

    printf("Enter car mileage: ");
    scanf("%f", &cars[*count].mileage);

    (*count)++;
    printf("Car added successfully!\n");
}
//end add car
// Function to display all cars
void displayCars(Car cars[], int count) {
    if (count == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\n--- List of Available Cars ---\n");
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %.2f km/l\n", cars[i].mileage);
        printf("-------------------------------\n");
    }
}
//end display car
// Function to search cars
void searchCarByMakeOrModel(Car cars[], int count, const char *keyword) {
    int found = 0;

    printf("\n--- Search Results for '%s' ---\n", keyword);
    for (int i = 0; i < count; i++) {
        if (strstr(cars[i].make, keyword) != NULL || strstr(cars[i].model, keyword) != NULL) {
            printf("Car %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %.2f km/l\n", cars[i].mileage);
            printf("-------------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching '%s'.\n", keyword);
    }
}
//end search by make or model