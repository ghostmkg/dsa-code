#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSumBrute(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<vector<int>> s;
        if (nums.size() < 3)
        {
            return result;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> ans = {nums[i], nums[j], nums[k]};
                        sort(ans.begin(), ans.end());
                        s.insert(ans);
                    }
                }
            }
        }
        for (auto &triplet : s)
        {
            result.push_back(triplet);
        }
        return result;
    }

    vector<vector<int>> threeSumBetter(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<vector<int>> s;
        if (nums.size() < 3)
        {
            return result;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            set<int> seen;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int complement = -nums[i] - nums[j];
                if (seen.find(complement) != seen.end())
                {
                    vector<int> ans = {nums[i], nums[j], complement};
                    sort(ans.begin(), ans.end());
                    s.insert(ans);
                }
                seen.insert(nums[j]);
            }
        }
        for (auto &triplet : s)
        {
            result.push_back(triplet);
        }
        return result;
    }

    vector<vector<int>> threeSumOptimal(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3)
        {
            return ans;
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            { // want i != j != k
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> res = {nums[i], nums[j], nums[k]};
                    ans.push_back(res);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
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
    vector<int> nums = {1, -1, 0, 2, -2, 1, -4};
    vector<vector<int>> result = s.threeSumOptimal(nums);
    for (auto &triplet : result)
    {
        for (auto &num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}