// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:6
#include <stdio.h>
//function to find multipple of a single number
void find_dup(int arr[], int N) {
    // assign a count array for everyone
     // Since elements are from 0 to N-1 as given in question
    int count[N];
    // assign all counts to 0
    for (int i = 0; i < N; i++)
        count[i] = 0; 

    // input array and increase the count
    for (int i = 0; i < N; i++)
        count[arr[i]]++;

    // Step 3: Print elements that occur more than once
    int found = 0;
    for (int i = 0; i < N; i++) {
        if (count[i] > 1) {
            printf("Number %d occurs more than once.\n", i);
            found = 1;
        }
    }

    // If no duplicates are found
    if (!found) {
        printf("No elements occur more than once.\n");
    }
}

int main() {
    int N = 5;
    int arr[] = {2, 3, 1, 2, 3}; // Example input

    // Find and print elements that occur more than once
    find_dup(arr, N);

    return 0;
}
