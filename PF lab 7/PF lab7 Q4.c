// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:4
#include <stdio.h>
//start main
int main() {
    // assign the array
    int arr[] = {4, 1, 6, 8, 10, 21, 8, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]); 
    // Calculate the size of the array

    // assign min and max with the first element of array
    int min = arr[0];
    int max = arr[0];

    //  for loop the array to find min and max
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];  // Update min if current element is smaller
        }
        if (arr[i] > max) {
            max = arr[i];  // Update max if current element is larger
        }
    }
    //end for loop

    // Print results
    printf("Minimum Number = %d\n", min);
    printf("Maximum Number = %d\n", max);

    return 0;
}
//end main
