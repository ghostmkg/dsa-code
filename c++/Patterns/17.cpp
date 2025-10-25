#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "   ";
        }

        char c = 'A';
        for (int j = 0; j <= (2 * i); j++) {
            cout << " " << (char)(c) << " ";
            if (j < i) {
                c++;
            } else {
                c--;
            }
        }
        cout << endl;
    }

    return 0;
}