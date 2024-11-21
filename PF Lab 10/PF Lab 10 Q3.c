// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q3
#include <stdio.h>

// Function to compare temperature with limit and count exceedances
void checkTemperature(float temp, float limit) {
    static int exceedCount = 0; // Static variable to keep count of exceedances

    if (temp > limit) {
        exceedCount++;
        printf("Temperature %.2f exceeds the limit of %.2f!\n", temp, limit);
    } else {
        printf("Temperature %.2f is within the limit of %.2f.\n", temp, limit);
    }

    printf("Number of times temperatures exceeded the limit so far: %d\n", exceedCount);
}
//start main
int main() {
    float limit;
    int n;

    // Input the maximum allowable temperature
    printf("Enter the maximum allowable temperature (in Celsius): ");
    scanf("%f", &limit);

    // Input the number of temperatures to check
    printf("Enter the number of temperatures to check: ");
    scanf("%d", &n);

    // Check each temperature
    printf("Enter the temperatures (in Celsius):\n");
    for (int i = 0; i < n; i++) {
        float temp;
        scanf("%f", &temp);
        checkTemperature(temp, limit);
    }

    return 0;
}
//end main
