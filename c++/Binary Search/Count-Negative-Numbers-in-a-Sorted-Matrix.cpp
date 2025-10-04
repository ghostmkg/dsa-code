#include <iostream>
#include <math.h>
using namespace std;
int countNegatives(vector<vector<int>> &nums)
{
    int cnt = 0;
    int n = nums.size();
    int m = nums[0].size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (nums[i][j] >= 0)
            {
                break;
            }
            else
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int>> nums = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

    cout << "count Negatives : " << countNegatives(nums) << endl;
    return 0;
}