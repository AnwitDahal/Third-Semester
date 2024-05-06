#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of bits of the binary numbers: ");
    scanf("%d", &n);
    int num1[n], num2[n], sum[n + 1]; 
    int carry = 0;
    printf("\nEnter the first binary number: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num1[i]);
    }

    printf("\nEnter the second binary number: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num2[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        sum[i + 1] = (num1[i] + num2[i] + carry) % 2;
        carry = (num1[i] + num2[i] + carry) / 2;
    }
    sum[0] = carry; 

    printf("\nThe sum of the two binary numbers is: ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d", sum[i]);
    }
    printf("\n");

    return 0;
}

