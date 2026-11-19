#include <stdio.h>

int totalCalories(int n) {
    if (n <= 0) {
        return 0;
    }
    return (n * 5) + totalCalories(n - 1);
}

int main() {
    int steps;
    printf("Enter number of steps: ");
    if (scanf("%d", &steps) != 1 || steps < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Total calories burned: %d\n", totalCalories(steps));
    return 0;
}