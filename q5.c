#include <stdio.h>

float calculateTotal(int n) {
    if (n <= 0) {
        return 0.0f;
    }
    float price;
    printf("Enter price of product: ");
    scanf("%f", &price);
    return price + calculateTotal(n - 1);
}

int main() {
    int count;
    printf("Enter number of products: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Total cost: 0.00\nAverage price: 0.00\n");
        return 0;
    }

    float total = calculateTotal(count);
    float average = total / count;

    printf("Total cost: %.2f\n", total);
    printf("Average price: %.2f\n", average);
    return 0;
}