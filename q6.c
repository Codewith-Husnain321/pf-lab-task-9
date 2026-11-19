#include <stdio.h>

int processExits(int remaining, int exitsLeft, int *exitedCount) {
    if (exitsLeft <= 0) {
        return remaining;
    }
    if (remaining <= 0) {
        printf("No vehicles left in the parking area to exit.\n");
        return 0;
    }

    remaining--;
    (*exitedCount)++;
    printf("Vehicle exited. Remaining vehicles: %d\n", remaining);

    return processExits(remaining, exitsLeft - 1, exitedCount);
}

int main() {
    int totalParked, vehiclesExiting, exitedCount = 0;

    printf("Enter total number of vehicles currently parked: ");
    scanf("%d", &totalParked);

    printf("Enter number of vehicles exiting: ");
    scanf("%d", &vehiclesExiting);

    int finalRemaining = processExits(totalParked, vehiclesExiting, &exitedCount);

    printf("\nTotal vehicles exited: %d\n", exitedCount);
    printf("Remaining vehicles: %d\n", finalRemaining);
    if (finalRemaining == 0) {
        printf("Parking status: Empty\n");
    } else {
        printf("Parking status: Not empty\n");
    }

    return 0;
}