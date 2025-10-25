#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    cout << endl;
    cout << endl;
    cout << endl;
    // face

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 3 * (n / 2); j++) {
            cout << "   ";
        }
        for (int j = 0; j < n - 1; j++) {
            if (i == j + 1 || (i == 0 && j == 0)
                || (i == 0 && j == n - 2)
                || (i == n - 1 && j == 0)
                || (i == n - j - 1)
                || (i == n - 1 && j == n - 2)) {
                cout << "   ";
            } else if (i == n - 1) {
                cout << " - ";
            } else if (j == 0 || j == n - 2) {
                cout << " o ";
            } else if (i == 0) {
                cout << "   ";
            } else {
                cout << " * ";
            }
        }
        cout << endl;
    }
    // neck
    for (int i = 0; i < n / 4 - 1; i++) {
        for (int j = 0; j <= 3 * (n / 2); j++) {
            cout << "   ";
        }
        // for (int j = 0; j < 2 * ((n / 4) - i) - 2; j++) {
        //     cout << " | ";
        // }

        cout << " -";
        cout << "                 ";
        cout << "- ";
        cout << endl;
    }

    // wings
    n *= (3 / 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * i; j++) {
            cout << "   ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << " " << i + 1 << " ";
        }
        for (int j = 0; j < 2 * (n - i) - 1; j++) {
            if (i == 0 && ((j == n) || (j == n - 2))) {
                cout << " * ";
            } else if (i == 0) {
                cout << "   ";
            } else if ((i <= (n / 2) + 1) && (j % 2 == 0) && (j != 0) && (j != (2 * ((n - i) - 1)))) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        };
        for (int j = 0; j < n - i; j++) {
            cout << " " << i + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    return 0;
}