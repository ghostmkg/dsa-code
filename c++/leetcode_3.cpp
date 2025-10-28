// Longest Substring Without Repeating Characters
// Leetcode Profile: https://leetcode.com/The_STK/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        if (mp.find(s[right]) != mp.end()) {
            left = max(left, mp[s[right]] + 1);
        }
        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
}
