// Count number of set bits in an integer - Nithin
#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Removes the last set bit
        count++;
    }
    return count;
}

int main() {
    int num = 29; // binary 11101 → 4 set bits
    printf("Number of set bits in %d: %d\n", num, countSetBits(num));
    return 0;
}
