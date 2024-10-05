// Name:Masoom Khan Roll#24k0001 Lab:6 Q7
//this only works for armstrong number with 3 digits only
#include <stdio.h>
//for using mathemathivs functions example power function
#include <math.h>
//start main
int main() {
   //assign variables
 int num, originalNum, remainder, result = 0;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);
    ///put number "num" value in original number
    originalNum = num;
     //start while
    // Calculate the sum of cubes of "originalnumber"
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, 3); 
       // Cube of the "originalnumber"
        originalNum /= 10;
    }
    //end while
     //start if-else
    // Check if the sum of cubes is equal to the original number
    if (result == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
     //end if-else
   
    return 0;
}
 //end main