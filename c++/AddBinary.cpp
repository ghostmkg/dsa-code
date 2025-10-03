#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

    cout << "Add Binary: " << addBinary(a, b) << endl;
    return 0;
}
