// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q3
#include <stdio.h>

// Function to check  prime
int isPrime(int num) {
    if (num <= 1) {
    // 0 and 1 are not prime numbers 
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}
//start main
int main() {
    int number;

    printf("Enter numbers to check if they are prime (enter a negative number to quit):\n");
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);

        if (number < 0) {
          // condition tp exit the loop 
            break; 
        }

        if (isPrime(number)) {
            printf("%d is a prime number.\n", number);
        } else {
            printf("%d is not a prime number.\n", number);
        }
    }

    printf("Program terminated.\n");
    return 0;
}
//end main