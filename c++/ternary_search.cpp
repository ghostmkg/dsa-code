#include <iostream>
using namespace std;

int ternarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == x) return mid1;
        if (arr[mid2] == x) return mid2;

        if (x < arr[mid1]) return ternarySearch(arr, left, mid1 - 1, x);
        if (x > arr[mid2]) return ternarySearch(arr, mid2 + 1, right, x);
        return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    int result = ternarySearch(arr, 0, n - 1, x);
    cout << result << endl;
}
