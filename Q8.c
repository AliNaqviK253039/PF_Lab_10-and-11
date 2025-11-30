#include <stdio.h>

#define MTOKM 0.001   

double convertToKm(double meters) {
    static int callCount = 0; 
    callCount++;

    printf("Function called %d times.\n", callCount);

    return meters * MTOKM;
}

int main() {
    double meters;

    printf("Enter distance in meters: ");
    scanf("%lf", &meters);

    double kilometers = convertToKm(meters);

    printf("Distance in kilometers: %.3lf km\n", kilometers);

    printf("\nEnter another distance in meters: ");
    scanf("%lf", &meters);

    kilometers = convertToKm(meters);

    printf("Distance in kilometers: %.3lf km\n", kilometers);

    return 0;
}

