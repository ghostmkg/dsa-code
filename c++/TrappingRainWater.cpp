#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int>& height) {
    if (height.empty()) {
        return 0;
    }
    int left = 0;
    int right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int water_trapped = 0;
    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            }
            else {
                water_trapped += left_max - height[left];
            }
            left++;
        }
        else {
            if (height[right] >= right_max) {
                right_max = height[right];
            }
            else {
                water_trapped += right_max - height[right];
            }
            right--;
        }
    }
    return water_trapped;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main() {
    vector<int> elevation_map = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The elevation map is: ";
    printVector(elevation_map);
    cout << std::endl;
    int trapped_water_amount = trap(elevation_map);
    cout << "Total amount of trapped water: " << trapped_water_amount << std::endl;
    cout << "\n";
    vector<int> elevation_map_2 = {4, 2, 0, 3, 2, 5};
    cout << "The elevation map is: ";
    printVector(elevation_map_2);
    cout << std::endl;
    int trapped_water_amount_2 = trap(elevation_map_2);
    cout << "Total amount of trapped water: " << trapped_water_amount_2 << std::endl;
    return 0;
}
