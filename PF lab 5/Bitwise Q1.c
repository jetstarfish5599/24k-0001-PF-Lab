// Name:Masoom Khan Roll#24k0001 Bitwise Q1
#include <stdio.h>
//function for swapping a and b
void swap_numbers(int *a, int *b) {
    printf("Before swapping: a = %d, b = %d\n", *a, *b);

    // Swap using XOR operation
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    printf("After swapping: a = %d, b = %d\n", *a, *b);
}
//start main
int main() {
 //assign variable
  int a,b;
  //user input of variable
  printf("Value of a:");
  scanf("%d", &a);
     printf("Value of b:");
  scanf("%d", &b);
   //Call the function
    swap_numbers(&a, &b);
    
    return 0;
}
//end main