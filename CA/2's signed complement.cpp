#include <stdio.h>
#include <stdlib.h> 
int add(int a, int b) {
    int carry = 0;
    for (int i = 0; i < 4; ++i) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int sum = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | ((bitA ^ bitB) & carry);
        a = a & ~(1 << i) | (sum << i);
    }
    return a;
}
int subtract(int a, int b) {
    return add(a, add(~b, 1)); 
}
void printBinary4Bit(int num) {
    for (int i = 3; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    char binaryInput1[5], binaryInput2[5];

    printf("Enter the first signed 4-bit 2's complement number in binary form: ");
    scanf("%s", binaryInput1);

    printf("Enter the second signed 4-bit 2's complement number in binary form: ");
    scanf("%s", binaryInput2);

    int num1 = (int)strtol(binaryInput1, NULL, 2);
    int num2 = (int)strtol(binaryInput2, NULL, 2);

    int sum = add(num1, num2);
    printf("Sum (binary): ");
    printBinary4Bit(sum);
    printf("\n");
    
    int difference = subtract(num1, num2);
    printf("Difference (binary): ");
    printBinary4Bit(difference);
    printf("\n");

    return 0;
}

