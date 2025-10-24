#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            for (int j = 0; j <= i; j++) {
                cout << " * ";
            }
            for (int j = 0; j < 2 * (n - i - 1); j++) {
                cout << "   ";
            }

            for (int j = 0; j <= i; j++) {
                cout << " * ";
            }
            cout << endl;
        } else {
            for (int j = 0; j < (2 * n) - i; j++) {
                cout << " * ";
            }
            for (int j = 0; j < 2 * (i - n); j++) {
                cout << "   ";
            }

            for (int j = 0; j < (2 * n) - i; j++) {
                cout << " * ";
            }
            cout << endl;
        }
    }

    return 0;
}