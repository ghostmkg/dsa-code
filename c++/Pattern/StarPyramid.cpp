#include <iostream>
using namespace std;

int main() {
    int n = 5; // number of rows
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++)
            cout << " ";
        for(int j = 1; j <= 2*i-1; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
