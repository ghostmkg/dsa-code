#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSumBrute(vector<int> nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == 0)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        for (auto val : s)
        {
            ans.push_back(val);
        }
        return ans;
    }

    vector<vector<int>> fourSumBetter(vector<int> nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        if (n < 4)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                set<int> hashset;
                for (int k = j + 1; k < n; k++)
                {
                    int fourth = -(nums[i] + nums[j] + nums[k]);
                    if (hashset.find(fourth) != hashset.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        for (auto val : s)
        {
            ans.push_back(val);
        }
        return ans;
    }

    vector<vector<int>> fourSumOptimal(vector<int> nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n < 4)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (j > 0 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < 0)
                    {
                        k++;
                    }
                    else if (sum > 0)
                    {
                        l--;
                    }
                    else
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = s.fourSumOptimal(nums);
    for (const auto &vec : result)
    {
        cout << "[";
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}