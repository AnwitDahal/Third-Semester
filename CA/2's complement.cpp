#include <stdio.h>

int main() {
    int n, k;
    printf("Enter the number of bits of binary number: ");
    scanf("%d", &n);
    int i[n], j[n], carry = 1;

    printf("\nEnter the binary number: ");
    for (k = 0; k < n; k++) {
        scanf("%d", &i[k]);
    }

    for (k = 0; k < n; k++) {
        if (i[k] == 0) {
            j[k] = 1;
        } else {
            j[k] = 0;
        }
    }

    for (k = n - 1; k >= 0; k--) {
        if (j[k] == 0 && carry == 1) {
            j[k] = 1;
            carry = 0;
        } else if (j[k] == 1 && carry == 1) {
            j[k] = 0;
        }
    }

    printf("\n2's complement: ");
    for (k = 0; k < n; k++) {
        printf("%d", j[k]);
    }
    return 0;
}


