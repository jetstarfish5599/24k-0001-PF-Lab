// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:11   Q4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSENGERS 1000
#define MAX_NAME_LEN 100
//put struct here
typedef struct {
    int passengerId;
    int survived;
    int pclass;
    char name[MAX_NAME_LEN];
    char sex[10];
    float age;
    int sibSp;
    int parch;
    char ticket[20];
    float fare;
    char cabin[20];
    char embarked[5];
} Passenger;
//put data function here
void loadData(const char *filename, Passenger passengers[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[1024];
    int i = 0;

    // Skip header
    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file)) {
        Passenger p = {0};
        sscanf(buffer, "%d,%d,%d,%[^,],%[^,],%f,%d,%d,%[^,],%f,%[^,],%s",
               &p.passengerId, &p.survived, &p.pclass, p.name, p.sex, &p.age,
               &p.sibSp, &p.parch, p.ticket, &p.fare, p.cabin, p.embarked);

        passengers[i++] = p;
    }

    *count = i;
    fclose(file);
}
// function for age calculation
float calculateAverageAge(Passenger passengers[], int count) {
    float totalAge = 0;
    int validAges = 0;

    for (int i = 0; i < count; i++) {
         // remove missing ages
        if (passengers[i].age > 0) {
            totalAge += passengers[i].age;
            validAges++;
        }
    }

    return validAges > 0 ? totalAge / validAges : 0.0;
}
//function for survival chance
void calculateSurvivalRate(Passenger passengers[], int count) {
    int maleSurvived = 0, maleTotal = 0;
    int femaleSurvived = 0, femaleTotal = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].sex, "male") == 0) {
            maleTotal++;
            if (passengers[i].survived) maleSurvived++;
        } else if (strcmp(passengers[i].sex, "female") == 0) {
            femaleTotal++;
            if (passengers[i].survived) femaleSurvived++;
        }
    }

    printf("Male Survival Rate: %.2f%%\n", maleTotal > 0 ? (maleSurvived * 100.0 / maleTotal) : 0.0);
    printf("Female Survival Rate: %.2f%%\n", femaleTotal > 0 ? (femaleSurvived * 100.0 / femaleTotal) : 0.0);
}
// list of survivors function
void displaySurvivors(Passenger passengers[], int count) {
    printf("List of Survivors:\n");
    printf("Name, Age, Class\n");
    for (int i = 0; i < count; i++) {
        if (passengers[i].survived) {
            printf("%s, %.1f, %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }
}
//function to show missing cabins
void displayMissingCabins(Passenger passengers[], int count) {
    printf("Passengers with Missing Cabin Details:\n");
    printf("Name, Class, Age\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].cabin, "") == 0 || strcmp(passengers[i].cabin, " ") == 0) {
            printf("%s, %d, %.1f\n", passengers[i].name, passengers[i].pclass, passengers[i].age);
        }
    }
}
//function to move result to file
void writeResultsToFile(const char *filename, Passenger passengers[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not write to file.\n");
        return;
    }

    fprintf(file, "Name, Age, Class\n");
    for (int i = 0; i < count; i++) {
        if (passengers[i].survived) {
            fprintf(file, "%s, %.1f, %d\n", passengers[i].name, passengers[i].age, passengers[i].pclass);
        }
    }

    fclose(file);
    printf("Results written to %s\n", filename);
}
//start main
int main() {
    // Declare variables
    Passenger passengers[MAX_PASSENGERS];
    int count = 0;

    // Step 1: Load the dataset
    printf("Loading Titanic dataset...\n");
    loadData("Titanic-Dataset.csv", passengers, &count);
    printf("Dataset loaded successfully. Total passengers: %d\n\n", count);

    // Step 2: Calculate and display the average age of passengers
    printf("Calculating average age of passengers...\n");
    float avgAge = calculateAverageAge(passengers, count);
    printf("Average Age: %.2f years\n\n", avgAge);

    // Step 3: Calculate and display survival rates based on gender
    printf("Calculating survival rates by gender...\n");
    calculateSurvivalRate(passengers, count);
    printf("\n");

    // Step 4: Display the list of survivors
    printf("Displaying the list of survivors...\n");
    displaySurvivors(passengers, count);
    printf("\n");

    // Step 5: Display passengers with missing cabin details
    printf("Displaying passengers with missing cabin details...\n");
    displayMissingCabins(passengers, count);
    printf("\n");

    // Step 6: Write survivors' details to a CSV file
    printf("Writing survivors' details to a CSV file...\n");
    writeResultsToFile("survivors.csv", passengers, count);
    printf("Analysis complete. Results saved to 'survivors.csv'.\n");

    return 0;
}
//end main