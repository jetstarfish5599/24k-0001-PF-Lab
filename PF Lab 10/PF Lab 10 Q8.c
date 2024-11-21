// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q8
#include <stdio.h>

// Recursive function for linear search
int linearSearch(int arr[], int size, int target, int index) {
    // TArget not in array
    if (index >= size) {
        return -1;
    }

    // Check if the current element matches the target
    if (arr[index] == target) {
        return index;
    }

    // Recursive case
    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[50];
    int target, result;

    // Fill the array with some values
    printf("Enter 50 integers for the array:\n");
    for (int i = 0; i < 50; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Call function
    result = linearSearch(arr, 50, target, 0);

    // Display result
    if (result != -1) {
        printf("Target element %d found at index %d.\n", target, result);
    } else {
        printf("Target element %d not found in the array.\n", target);
    }

    return 0;
}
//end main 