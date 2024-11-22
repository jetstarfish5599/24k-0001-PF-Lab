// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:11   Q1
#include <stdio.h>
#include <string.h>

// Structure to represent an employee
typedef struct {
    char name[50];
    int employeeID;
    float salary;
} Employee;

// Structure to represent a department
typedef struct {
    char departmentName[50];
    int employeeCount;
   // Array to store multiple employees
    Employee employees[100]; 
} Department;

// Function to calculate the total salary of all employees in a department
float calculateTotalSalary(Department department) {
    float totalSalary = 0;
    for (int i = 0; i < department.employeeCount; i++) {
        totalSalary += department.employees[i].salary;
    }
    return totalSalary;
}
//start main
int main() {
    Department department;

    // Input department details
    printf("Enter the department name: ");
    fgets(department.departmentName, 50, stdin);
    department.departmentName[strcspn(department.departmentName, "\n")] = '\0'; // Remove newline character

    printf("Enter the number of employees in the department: ");
    scanf("%d", &department.employeeCount);

    if (department.employeeCount <= 0) {
        printf("Invalid number of employees!\n");
        return 1;
    }

    // Input employee details
    for (int i = 0; i < department.employeeCount; i++) {
        printf("\n--- Enter details for employee %d ---\n", i + 1);
        getchar(); // Clear newline from buffer

        printf("Name: ");
        fgets(department.employees[i].name, 50, stdin);
        department.employees[i].name[strcspn(department.employees[i].name, "\n")] = '\0'; // Remove newline

        printf("Employee ID: ");
        scanf("%d", &department.employees[i].employeeID);

        printf("Salary: ");
        scanf("%f", &department.employees[i].salary);
    }

    // Calculate and display the total salary
    float totalSalary = calculateTotalSalary(department);
    printf("\nThe total salary of all employees in the '%s' department is: %.2f\n",
           department.departmentName, totalSalary);

    return 0;
}
//end main