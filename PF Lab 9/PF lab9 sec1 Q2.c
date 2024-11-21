// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9   section:1    Q2
#include <stdio.h>

// Function for even or odd
void checkEvenOrOdd(int num) {
    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}
//start main
int main() {
    int number;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the function
    checkEvenOrOdd(number);

    return 0;
}
//end main
