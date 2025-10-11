#include <iostream>
using namespace std;

void multiplyMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[2][2], B[2][2], result[2][2];
    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];
    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];
    multiplyMatrices(A, B, result);
    cout << "Product of matrices A and B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
