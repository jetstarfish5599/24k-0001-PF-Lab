// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function to compare employees
int compareBySalary(const void *a, const void *b) {
    Employee *empA = (Employee *)a;
    Employee *empB = (Employee *)b;
    return (empA->salary > empB->salary) - (empA->salary < empB->salary);
}
//start main
int main() {
    int n;

    // Input the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for employees
    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee details
    printf("Enter details if employees (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Sort employees by salary
    qsort(employees, n, sizeof(Employee), compareBySalary);

    // Output sorted employee details
    printf("\nEmployees sorted by salary:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].salary);
    }

    // Free allocated memory
    free(employees);

    return 0;
}
//end main