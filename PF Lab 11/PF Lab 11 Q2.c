// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:11   Q2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
typedef struct {
    char name[50];
    int employeeID;
    float salary;
} Employee;

// Function prototypes
void addEmployeeRecords(const char *filename);
void displayAndCalculateTotalSalary(const char *filename);
//start main
int main() {
    const char *filename = "employee_salaries.dat";
    int choice;

    while (1) {
        printf("\n--- Employee Salary Record System ---\n");
        printf("1. Add Employee Records\n");
        printf("2. Display Records and Calculate Total Salary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployeeRecords(filename);
                break;
            case 2:
                displayAndCalculateTotalSalary(filename);
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
// Function to add employee records
void addEmployeeRecords(const char *filename) {
    FILE *file = fopen(filename, "ab"); // Open file in append binary mode
    if (!file) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    int n;

    printf("Enter the number of employees to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar(); // Clear newline from buffer
        printf("\n--- Employee %d ---\n", i + 1);
        printf("Name: ");
        fgets(emp.name, 50, stdin);
        emp.name[strcspn(emp.name, "\n")] = '\0';

        printf("Employee ID: ");
        scanf("%d", &emp.employeeID);

        printf("Salary: ");
        scanf("%f", &emp.salary);

        // Write the record to the binary file
        fwrite(&emp, sizeof(Employee), 1, file);
    }

    printf("\nEmployee records added successfully.\n");
    fclose(file);
}
//end employee record function
// Function to display employee records and calculate the total salary
void displayAndCalculateTotalSalary(const char *filename) {
    FILE *file = fopen(filename, "rb"); // Open file in read binary mode
    if (!file) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    float totalSalary = 0;
    int recordCount = 0;

    printf("\n--- Employee Records ---\n");
    while (fread(&emp, sizeof(Employee), 1, file) == 1) {
        printf("Name: %s\n", emp.name);
        printf("Employee ID: %d\n", emp.employeeID);
        printf("Salary: %.2f\n", emp.salary);
        printf("-------------------------\n");

        totalSalary += emp.salary;
        recordCount++;
    }

    if (recordCount == 0) {
        printf("No records found in the file.\n");
    } else {
        printf("\nTotal Salary Expense: %.2f\n", totalSalary);
    }

    fclose(file);
}
//end display salary function 