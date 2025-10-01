#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	// Find Minimum of a and b
    int res = min(a, b);

  	// Testing divisiblity with all numbers starting from
	// min(a, b) to 1

    while (res > 1) {

        // If any number divide both a and b, so we
        // got the answer
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
	return res;
}

int main() {
    int a = 12, b = 16;
  
	// Finding gcd of two numbers a and b


    cout << gcd(a, b);
    return 0;
}