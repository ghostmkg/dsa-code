#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n - 1);
    long long ans = 0;
    for(long long i = 0; i < n - 1; i++){
        cin >> a[i];
        ans += a[i];
    }
    long long sum = (n * (n + 1)) / 2;
    cout << sum - ans << endl;
    return 0;
}
