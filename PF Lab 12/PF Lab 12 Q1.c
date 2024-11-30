// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q1
#include <stdio.h>

// Function to reverse an array using pointers
void reverseArray(int *arr, int size) {
    int *start = arr;           // Pointer to the first element
    int *end = arr + size - 1;  // Pointer to the last element

    while (start < end) {
        // Swap the values pointed to by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers closer to each other
        start++;
        end--;
    }
}
//start main
int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    reverseArray(arr, n);

    // Output the reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//end main