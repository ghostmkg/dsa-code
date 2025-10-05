#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    int row = 0;
    while (n >= row + 1) {
        row++;
        n -= row;
    }

    cout << "Number of complete rows: " << row << endl;
    return 0;
}
