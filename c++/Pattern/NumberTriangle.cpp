#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
