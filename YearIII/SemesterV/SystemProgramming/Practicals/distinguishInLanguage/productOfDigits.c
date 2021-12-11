/**
 * @file productOfDigits.c
 * @author Shubhang Gupta
 * @brief The code computes the product of digits of an input number.
 * @version 0.1
 * @date 2021-08-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

int main() {
    /* Declaration of identifiers. */
    int num;
    int rem;
    float product = 1.0;

    /* Take input from the user. */
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int i = 0; num != 0; i++) {
        rem = num % 10;    // Get the last digit of the number
        product *= rem;    // Multiply the digit with product
        num /= 10;         // Remove the last digit from the number
    }

    /* Print the result. */
    printf("Product of digits: %d\n", product);

    return 0;
}