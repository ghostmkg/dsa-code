#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (((i % 2 == 0) && (j % 2 == 0)) || (i % 2 != 0) && (j % 2 != 0)) {
                cout << " " << j - j + 1 << " ";
            } else {
                cout << " " << j - j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}