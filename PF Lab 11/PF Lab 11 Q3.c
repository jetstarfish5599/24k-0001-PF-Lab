// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:11   Q3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 6
#define MAX_STUDENTS 50

// Structure to represent a course
typedef struct {
    char name[50];
    char code[10];
    char instructor[50];
} Course;

// Structure to represent a student
typedef struct {
    char name[50];
    int rollNumber;
    int enrolledCoursesCount;
    Course courses[MAX_COURSES];
} Student;

// Global variables
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent(const char *filename);
void displayStudentCourses(const char *filename);
void generateReport(const char *filename);
void modifyEnrollment(const char *filename);

// Function to add student and their course enrollment
void addStudent(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("\nEnter Student Name: ");
    getchar(); // Clear buffer
    fgets(student.name, 50, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNumber);

    printf("Enter the number of courses the student is enrolling in (max %d): ", MAX_COURSES);
    scanf("%d", &student.enrolledCoursesCount);

    if (student.enrolledCoursesCount > MAX_COURSES) {
        printf("Error: Too many courses! Maximum allowed is %d.\n", MAX_COURSES);
        fclose(file);
        return;
    }

    for (int i = 0; i < student.enrolledCoursesCount; i++) {
        getchar(); // Clear buffer
        printf("\n--- Course %d ---\n", i + 1);
        printf("Course Name: ");
        fgets(student.courses[i].name, 50, stdin);
        student.courses[i].name[strcspn(student.courses[i].name, "\n")] = '\0';

        printf("Course Code: ");
        fgets(student.courses[i].code, 10, stdin);
        student.courses[i].code[strcspn(student.courses[i].code, "\n")] = '\0';

        printf("Instructor: ");
        fgets(student.courses[i].instructor, 50, stdin);
        student.courses[i].instructor[strcspn(student.courses[i].instructor, "\n")] = '\0';
    }

    // Save to file
    fwrite(&student, sizeof(Student), 1, file);
    printf("Student enrollment data saved successfully.\n");

    fclose(file);
}

// Function to display courses enrolled by a student
void displayStudentCourses(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    int rollNumber;
    int found = 0;

    printf("Enter the roll number of the student: ");
    scanf("%d", &rollNumber);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.rollNumber == rollNumber) {
            found = 1;
            printf("\nStudent Name: %s\n", student.name);
            printf("Roll Number: %d\n", student.rollNumber);
            printf("Enrolled Courses:\n");
            for (int i = 0; i < student.enrolledCoursesCount; i++) {
                printf("  %d. %s (Code: %s, Instructor: %s)\n",
                       i + 1, student.courses[i].name, student.courses[i].code, student.courses[i].instructor);
            }
            break;
        }
    }

    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }

    fclose(file);
}

// Function to generate a report of students enrolled in each course
void generateReport(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    char courseName[50];
    int courseCount[MAX_COURSES] = {0};
    char courses[MAX_COURSES][50];
    int uniqueCourseCount = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        for (int i = 0; i < student.enrolledCoursesCount; i++) {
            int found = 0;
            for (int j = 0; j < uniqueCourseCount; j++) {
                if (strcmp(courses[j], student.courses[i].name) == 0) {
                    courseCount[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(courses[uniqueCourseCount], student.courses[i].name);
                courseCount[uniqueCourseCount]++;
                uniqueCourseCount++;
            }
        }
    }

    printf("\n--- Enrollment Report ---\n");
    for (int i = 0; i < uniqueCourseCount; i++) {
        printf("Course: %s, Students Enrolled: %d\n", courses[i], courseCount[i]);
    }

    fclose(file);
}

// Function to modify a student's course enrollment
void modifyEnrollment(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    int rollNumber;
    int found = 0;
    long pos;

    printf("Enter the roll number of the student: ");
    scanf("%d", &rollNumber);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.rollNumber == rollNumber) {
            found = 1;
            pos = ftell(file) - sizeof(Student);

            printf("\nModifying enrollment for %s (Roll No: %d)\n", student.name, student.rollNumber);
            printf("Enter the new number of courses: ");
            scanf("%d", &student.enrolledCoursesCount);

            for (int i = 0; i < student.enrolledCoursesCount; i++) {
                getchar(); // Clear buffer
                printf("\n--- Course %d ---\n", i + 1);
                printf("Course Name: ");
                fgets(student.courses[i].name, 50, stdin);
                student.courses[i].name[strcspn(student.courses[i].name, "\n")] = '\0';

                printf("Course Code: ");
                fgets(student.courses[i].code, 10, stdin);
                student.courses[i].code[strcspn(student.courses[i].code, "\n")] = '\0';

                printf("Instructor: ");
                fgets(student.courses[i].instructor, 50, stdin);
                student.courses[i].instructor[strcspn(student.courses[i].instructor, "\n")] = '\0';
            }

            // Update the file
            fseek(file, pos, SEEK_SET);
            fwrite(&student, sizeof(Student), 1, file);
            printf("Enrollment data updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("No student found with roll number %d.\n", rollNumber);
    }

    fclose(file);
}

int main() {
    const char *filename = "student_courses.dat";
    int choice;

    while (1) {
        printf("\n--- Student Course Enrollment System ---\n");
        printf("1. Add Student and Course Enrollment\n");
        printf("2. Display Courses Enrolled by a Student\n");
        printf("3. Generate Enrollment Report\n");
        printf("4. Modify Course Enrollment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                displayStudentCourses(filename);
                break;
            case 3:
                generateReport(filename);
                break;
            case 4:
                modifyEnrollment(filename);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}