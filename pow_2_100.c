#include <stdio.h>

// What is 2 raised to the power of 100?

int main() {
    int result[31] = {0};
    int i = 30;
    int length = 1;
    result[i] = 1;
    for (int k=0; k<100; k++) {
        int carry = 0;
        for (int j=i; j>=0; j--) {
            result[j] = result[j] * 2 + carry;
            carry = 0;
            if (result[j] >= 10) {
                int temp = result[j];
                result[j] = temp % 10;
                carry = temp / 10;
                if (j-1 <= i-length) {
                    ++length;
                }
            }
        }
    }

    for (int j=i-length+1; j<=i; j++) {
        printf("%d", result[j]);
    }

    return 0;
}
