#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
        cout << endl
             << endl;
    }

    return 0;
}