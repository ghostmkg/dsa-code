#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the Number:";
    cin >> n;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            ch = '@' + (n - j);
            cout << " " << ch << " ";
        }
        cout << endl;
    }

    return 0;
}