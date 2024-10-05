// Name:Masoom Khan Roll#24k0001 Lab:6 Q6
#include <stdio.h>

// Function to check if a number is prime
int checkPrime(int num) {
    if (num <= 1) return 0; 
// 0 and 1 are not prime numbers
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0; 
// Not a prime number
        }
//end if
    }
//end for
    return 1; 
// Prime number
}
//end checck prime function

// Function to print Fibonacci series up to 'num'
void printfibonacci(int num) {
    int t1 = 0, t2 = 1, nextTerm = 0;

    printf("Series is = ");
    for (int i = 1; nextTerm <= num; ++i) {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    printf("\n");
}
  // end Fibonacci series        

int main() {
    int num;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is prime
    if (checkPrime(num)) {
        printf("Number is prime\n");
       
 // Print Fibonacci series if the number is prime
        printfibonacci(num);
    } else {
        printf("Number is not prime\n");
    }

    return 0;
}