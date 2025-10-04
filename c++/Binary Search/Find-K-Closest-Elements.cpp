#include <iostream>
using namespace std;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> ans = findClosestElements(nums, k, x);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}