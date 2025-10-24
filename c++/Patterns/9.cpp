#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        if (i <= n) {
            for (int j = 0; j < n - i; j++) {
                cout << "   ";
            }
            for (int j = 0; j < (2 * i) - 1; j++) {
                cout << " * ";
            }
            cout << endl;
        } else {
            for (int j = 0; j < i - n - 1; j++) {
                cout << "   ";
            }
            for (int j = 0; j <= (2 * ((2 * n) - i)); j++) {
                cout << " * ";
            }
            cout << endl;
        }
    }

    return 0;
}