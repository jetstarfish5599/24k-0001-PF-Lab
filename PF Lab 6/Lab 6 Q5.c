// Name:Masoom Khan Roll#24k0001 Lab:6 Q5
#include <stdio.h>
//start main
int main() {
    //assign variables
int num, i, isPrime = 1;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // 0 and 1 are not prime numbers
   //start if-else
 if (num <= 1) {
        isPrime = 0;
    } else {
        // Check for factors other than 1 and num itself
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    //end if-else
    // Output the result
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
//end if-else
    return 0;
}