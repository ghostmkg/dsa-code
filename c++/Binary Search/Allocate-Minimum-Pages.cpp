#include <iostream>
#include <math.h>
using namespace std;

bool isPossible(vector<int> &nums, int k, int possible)
{
    int student = 1;
    int pages = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > possible)
        {
            return false;
        }
        if (nums[i] + pages <= possible)
        {
            pages += nums[i];
        }
        else
        {
            pages = nums[i];
            student++;
        }
    }
    return student <= k;
}

// Brute force solution
int findPagesBrute(vector<int> &nums, int k)
{
    if (nums.size() < k)
    {
        return -1;
    }
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;

    for (auto num : nums)
    {
        high += num;
    }
    for (int i = low; i <= high; i++)
    {
        if (isPossible(nums, k, i) == true)
        {
            return i;
        }
    }
    return -1;
}

// optimal force solution
int findPagesOptimal(vector<int> &nums, int k)
{
    if (nums.size() < k)
    {
        return -1;
    }
    int low = *min_element(nums.begin(), nums.end());
    int high = 0;

    for (auto num : nums)
    {
        high += num;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(nums, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> nums = {15, 10, 19, 10, 5, 18, 7};
    int k = 5;

    cout << "Minimun pages : " << findPagesBrute(nums, k) << endl;
    cout << "Minimun pages : " << findPagesOptimal(nums, k) << endl;
    return 0;
}