// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:9    Q6
#include <stdio.h>

// Function prototype
void findMaxMin(int arr[], int size, int *max, int *min);
// Function 
void findMaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
//start main
int main() {
    int n;

    // Input array size
    printf("Enter  elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    // Input elements ofarray
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;

    // Call function
    findMaxMin(arr, n, &max, &min);

    // Display the results
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
//end main

