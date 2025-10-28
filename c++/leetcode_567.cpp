//Permutation in String
//Leetcode Profile: https://leetcode.com/The_STK/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> count1(26, 0), count2(26, 0);

    for (char c : s1)
        count1[c - 'a']++;

    for (int i = 0; i < s1.size(); i++)
        count2[s2[i] - 'a']++;

    if (count1 == count2) return true;

    for (int i = s1.size(); i < s2.size(); i++) {
        count2[s2[i] - 'a']++;
        count2[s2[i - s1.size()] - 'a']--;
        if (count1 == count2) return true;
    }

    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) ? "true" : "false");
}
