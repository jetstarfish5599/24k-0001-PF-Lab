// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:8        Q2
#include <stdio.h>
//start main
int main() {
    int low, up, i, j, isPrime;

    // Input the range from the user
    printf("Enter the first number: ");
    scanf("%d", &low);
    printf("Enter the last number: ");
    scanf("%d", &up);

    printf("Prime numbers between %d and %d are: \n", low, up);

    // Loop through each number in the range
    for (i = low; i <= up; i++) {
        // Skip 1 as it is not a prime number
        if (i < 2) {
            continue;
        }
        
        // Assume the current number is prime
        isPrime = 1;
        // for and if start
        // Check if i is divisible by any number from 2 to sqrt(i)
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                // Set isPrime to 0 if divisible
                isPrime = 0;  
                break;       
            }
        }

        // If the number is prime, print it
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }
          //for and if end
    return 0;
}
//main end
