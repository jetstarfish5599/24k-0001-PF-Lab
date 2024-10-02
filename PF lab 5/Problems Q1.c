// Name:Masoom Khan Roll#24k0001 Problem Q1
#include <stdio.h>
//start main
int main() {
    int num1, num2, num3;

    // Take input for three numbers
    printf("Enter three numbers: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Nested if-else to find the greatest number
    if (num1 >= num2) {
        //start of if-else
        if (num1 >= num3) {
            printf("The greatest number is: %d\n", num1);
        } else {
            printf("The greatest number is: %d\n", num3);
        }
    } 
          //end of if-else
          else {
        //start of if-else
        if (num2 >= num3) {
            printf("The greatest number is: %d\n", num2);
        } else {
            printf("The greatest number is: %d\n", num3);
        }
        //end of if-else
    }
    //end of Nested if-else

    return 0;
}