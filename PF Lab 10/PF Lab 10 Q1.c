// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q1
#include <stdio.h>
// Function to print array elements
void printArrayRecursive(int arr[], int size, int index) {
    if (index >= size) {
        return; // Base case: when index reaches or exceeds size, stop recursion
    }

    // Print element
    printf("%d ", arr[index]);

    //Call next element
    printArrayRecursive(arr, size, index + 1);
}
//start main
int main() {
    int n;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call function
    printf("Array elements:\n");
    printArrayRecursive(arr, n, 0);

    return 0;
}
//end main

