// Name:Masoom Khan Roll#24k-0001         LAB:7 Q:5
#include <stdio.h>
//start main
int main() {
    // assign the array with temperatures for 7 days
    float temp[7] = {25, 30, -2, 35, 42, 28, 10};
    // Number of days in a week
    int n = 7;  
      // Calculate the sum of temperatures
    float sum = 0.0;
    
   //for loop starts
    for (int i = 0; i < n; i++) {
        sum += temp[i];
    }
    //end for loo[
    // Calculate the average temperature
    float ave = sum / n;
    printf("Average temperature: %.1f°C\n", ave);

    // Check for extreme temperatures
    printf("Extreme temperatures on day(s): ");
    int extr = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] > 40 || temp[i] < 0) {
            printf("%d ", i + 1);  
            // i+1 to output the day number (1-indexed)
            extr = 1;
        }
    }

    if (!extr) {
        printf("None");
    }

    printf("\n");

    return 0;
}
