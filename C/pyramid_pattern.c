// The Pattern will look something like this
//         1
//       1 2 1
//     1 2 3 2 1
//   1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1
//   1 2 3 4 3 2 1
//     1 2 3 2 1
//       1 2 1
//         1


#include <stdio.h>

int main() {
    int n, i, j, k;

    // Input the number of rows (half of the diamond)
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // UPPER HALF of diamond
    for (i = 1; i <= n; i++) {
        // Print leading spaces
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }

        // Print increasing numbers from 1 to i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Print decreasing numbers from i-1 down to 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        // New line after each row
        printf("\n");
    }

    // LOWER HALF of diamond
    for (i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }

        // Print increasing numbers from 1 to i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Print decreasing numbers from i-1 down to 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        // New line after each row
        printf("\n");
    }

    return 0;
}

