// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q5
#include <stdio.h>

// Recursive function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    // Base case: If the array size is 1, it is already sorted
    if (n == 1) {
        return;
    }

    // One pass of bubble sort: Move the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap adjacent elements if they are in the wrong order
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursive call for array
    bubbleSort(arr, n - 1);
}
//start main
int main() {
    int n;

    // Input the size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    // Input the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // CallBubble Sort function
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//end main