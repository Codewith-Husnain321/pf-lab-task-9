#include <stdio.h>

void reverseDigits(long num) {
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        return;
    }
    printf("%ld", num % 10);
    reverseDigits(num / 10);
}

int main() {
    long number;
    printf("Enter number: ");
    if (scanf("%ld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Reversed: ");
    if (number == 0) {
        printf("0");
    } else {
        reverseDigits(number);
    }
    printf("\n");
    return 0;
}