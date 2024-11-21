// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   section:1    Q1 
#include <stdio.h>
// Recursive function
int sumOfDigits(int num) {
    if (num == 0) {
        // stopping case
        return 0; 
    }
    // Recursion
    return (num % 10) + sumOfDigits(num / 10); 
}
//sstaart main
int main() {
    int num;

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call fuxnction
    int result = sumOfDigits(num);

    // Display result
    printf("Sum of digits: %d\n", result);

    return 0;
}
//end mai
