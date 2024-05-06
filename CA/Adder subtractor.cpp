#include <stdio.h>
#include <stdlib.h>

int* binaryAddition(int *a, int *b, int n, int *carryOut) {
    int *result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = a[i] ^ b[i] ^ carry;
        carry = (a[i] & b[i]) | (a[i] & carry) | (b[i] & carry);
    }
    *carryOut = carry;
    return result;
}

int* binarySubtraction(int *a, int *b, int n, int *borrowOut) {
    int *result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int borrow = 0;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = a[i] ^ b[i] ^ borrow;
        borrow = (~a[i] & b[i]) | ((~a[i] ^ b[i]) & borrow);
    }
    *borrowOut = borrow;
    return result;
}

int* decimalToBinary(int num, int n) {
    int *binary = (int*)malloc(n * sizeof(int));
    if (binary == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = n - 1; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
    return binary;
}

void freeMemory(int *ptr) {
    free(ptr);
}

void printBinary(int *binary, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", binary[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of bits for binary numbers: ");
    scanf("%d", &n);

    int *a, *b, control;
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    if (a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter the first binary number (in %d bits): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }

    printf("Enter the second binary number (in %d bits): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &b[i]);
    }

    printf("Enter the control signal (0 for addition, 1 for subtraction): ");
    scanf("%d", &control);

    int *result;
    int carryOut, borrowOut;

    if (control == 0) {
        result = binaryAddition(a, b, n, &carryOut);
        printf("Binary Addition Result: ");
        printBinary(result, n);
        printf("\nCarry Out: %d\n", carryOut);
    } else if (control == 1) {
        result = binarySubtraction(a, b, n, &borrowOut);
        printf("Binary Subtraction Result: ");
        printBinary(result, n);
        printf("\nBorrow Out: %d\n", borrowOut);
    } else {
        printf("Invalid control signal. Please enter 0 for addition or 1 for subtraction.\n");
        return 1;
    }

    freeMemory(a);
    freeMemory(b);
    freeMemory(result);

    return 0;
}

