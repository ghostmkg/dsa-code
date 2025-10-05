#include <iostream>
#include <math.h>
using namespace std;
bool comman(vector<int> &stalls, int k, int maxDis)
{
    int cow = 1;
    int cowPlace = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - cowPlace >= maxDis)
        {
            cowPlace = stalls[i];
            cow++;
        }
    }
    return cow >= k;
}
// Brute force solution
int aggressiveCowsBrute(vector<int> &stalls, int k)
{
    int low = 1;
    int high = *max_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end());

    for (int i = low; i <= high; i++)
    {
        if (comman(stalls, k, i))
        {
            continue;
        }
        else
        {
            return i - 1;
        }
    }
    return -1;
}
// Optimal solution
int aggressiveCowsOptimal(vector<int> &stalls, int k)
{
    int low = 1;
    int high = *max_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (comman(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> nums = {7, 11, 13};
    int k = 3;

    cout << "Aggressive Cows : " << aggressiveCowsBrute(nums, k) << endl;
    cout << "Aggressive Cows : " << aggressiveCowsOptimal(nums, k) << endl;

    return 0;
}