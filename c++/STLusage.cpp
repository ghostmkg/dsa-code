#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    vector numbers = {34,23,65,72};
    sort(numbers.begin(), numbers.end());
    for(int num : numbers){
        cout << num << " ";
    }
    return 0;
}