#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all 
// elements except the current element
vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
  
    // Fill result array with 1
    vector<int> res(n, 1);

    for (int i = 0; i < n; i++) {
      
        // Compute product of all elements except arr[i]
        for (int j = 0; j < n; j++) {
            if (i != j) 
                res[i] *= arr[j];
        }
    }

    return res;
}

int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);
    for (int val : res) 
        cout << val << " ";
    return 0;
}
