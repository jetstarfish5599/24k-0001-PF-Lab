// Name:Masoom Khan Roll#24k0001 Lab:6 Q2
#include <stdio.h>
//start main
int main() {
    int a, b, sum = 0;

    // Input from user
    printf("Enter two integers a and b: ");
    scanf("%d %d", &a, &b);

    // Ensure that 'a' <= 'b'
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Loop the range and sum even numbers
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {  // Check if the number is even
            sum += i;
        }
    }

    // Output sum
    printf("Sum of even numbers between %d and %d included= %d\n", a, b, sum);

    return 0;
}
//end main
