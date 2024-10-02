// Name:Masoom Khan Roll#24k0001 Problem Q2
#include <stdio.h>
//start main
int main() {
    float attendance, assignment, exam, final_grade;

    // Take input for the student's attendance, assignment score, and exam score respectively
    printf("Enter attendance percentage (out of 100): ");
    scanf("%f", &attendance);

    printf("Enter assignment score (out of 100): ");
    scanf("%f", &assignment);

    printf("Enter exam score (out of 100): ");
    scanf("%f", &exam);

    // Calculate the final grade with different weightage
    // Attendance: 10%, Assignment: 20%, Exam: 70%
    final_grade = (attendance * 0.10) + (assignment * 0.20) + (exam * 0.70);

    printf("\nFinal Grade: %.2f\n", final_grade);

    // Nested if-else to determine the grade
    if (final_grade >= 90) {
        printf("Letter Grade: A\n");
    } else if (final_grade >= 80) {
        printf("Letter Grade: B\n");
    } else if (final_grade >= 70) {
        if (attendance >= 75) {  // Additional check for attendance
            printf("Letter Grade: C\n");
        } else {
            printf("Letter Grade: D (due to poor attendance)\n");
        }
    } else if (final_grade >= 60) {
        printf("Letter Grade: D\n");
    } else {
        printf("Letter Grade: F\n");
    }

    return 0;
//end main