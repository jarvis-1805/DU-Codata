#include <stdio.h>

int main() {
    int num, rem, product = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int i = 0; num != 0; i++) {
        rem = num % 10;
        product *= rem;
        num /= 10;
    }

    printf("Product of digits: %d\n", product);

    return 0;
}