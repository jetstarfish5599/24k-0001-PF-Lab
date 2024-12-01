// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:12   Q4
#include <stdio.h>
#include <stdlib.h>
//start  main
int main() {
    int n;

    // Step 1: Input the initial size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Step 2: Dynamically allocate an array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Input values and calculate their sum
    printf("Enter %d integers:\n", n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of initial array: %d\n", sum);

    // Step 4: Reallocate the array to double its size
    int* newArr = (int*)realloc(arr, 2 * n * sizeof(int));
    if (newArr == NULL) {
        printf("Reallocation failed!\n");
        free(arr);
        return 1;
    }
    arr = newArr;

    // Step 5: Input n more values and calculate the new sum
    printf("Enter %d more integers:\n", n);
    for (int i = n; i < 2 * n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("New sum after adding more values: %d\n", sum);

    // Step 6: Clean up
    free(arr);
    return 0;
}
//end main