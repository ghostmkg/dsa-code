#include <iostream>

using namespace std;
int main()
{
    int n, c = 0;
    cout << "Enter the Number: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << " " << c + 1 << " ";
            c++;
        }
        cout << endl;
    }

    return 0;
}