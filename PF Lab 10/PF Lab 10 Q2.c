// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   Q2
#include <stdio.h>
#include <math.h>

// Define a structure for a point in 2D space
typedef struct {
    float x;
    float y;
} Point;
// Function to calculate the distance between two points
float calculateDistance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Function to check if a point lies within a rectangle
int isPointInRectangle(Point p, Point topLeft, Point bottomRight) {
    return (p.x >= topLeft.x && p.x <= bottomRight.x && 
            p.y <= topLeft.y && p.y >= bottomRight.y);
}
//start main
int main() {
    Point p1, p2, point, topLeft, bottomRight;

    // Input for distance calculation
    printf("Enter the coordinates of the first point (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter the coordinates of the second point (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    // Calculate and display the distance
    float distance = calculateDistance(p1, p2);
    printf("Distance between the points: %.2f\n", distance);

    // Input for rectangle boundary check
    printf("\nEnter the top-left corner of the rectangle (x y): ");
    scanf("%f %f", &topLeft.x, &topLeft.y);

    printf("Enter the bottom-right corner of the rectangle (x y): ");
    scanf("%f %f", &bottomRight.x, &bottomRight.y);

    printf("Enter the coordinates of the point to check (x y): ");
    scanf("%f %f", &point.x, &point.y);

    // Check if the point lies within the rectangle
    if (isPointInRectangle(point, topLeft, bottomRight)) {
        printf("The point lies within the rectangle.\n");
    } else {
        printf("The point does not lie within the rectangle.\n");
    }

    return 0;
}
//end main
