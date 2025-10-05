#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool comman(vector<int> &weights, int days, int leastWeights)
{
    int capacity = 0;
    int dayCount = 1;
    for (auto weight : weights)
    {
        if (weight > leastWeights)
        {
            return false;
        }

        if (capacity + weight <= leastWeights)
        {
            capacity += weight;
        }
        else
        {
            capacity = weight;
            dayCount++;
        }
    }
    return dayCount <= days;
}
int shipWithinDaysrBrute(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for (auto weight : weights)
    {
        high += weight;
    }
    for (int i = low; i < high; i++)
    {
        if (comman(weights, days, i))
        {
            return i;
        }
    }
    return -1;
}
int shipWithinDaysOptimal(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for (auto weight : weights)
    {
        high += weight;
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if(comman(weights, days, mid)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "ship Within Days Brute : " << shipWithinDaysrBrute(weights, days) << endl;
    cout << "ship Within Days Optimal : " << shipWithinDaysOptimal(weights, days) << endl;
    return 0;
}