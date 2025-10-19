#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string MinString(unordered_map<char,int>& freq) {
        string temp = "";
        for(char c = 'a'; c <= 'z'; c++){
            if(freq[c] > 0) temp += string(freq[c], c);
        }
        return temp;
    }

    string MaxString(unordered_map<char,int>& freq) {
        string temp = "";
        for(char c = 'z'; c >= 'a'; c--){
            if(freq[c] > 0) temp += string(freq[c], c);
        }
        return temp;
    }

    string nextGreaterPermutation(string s, string target) {
        int n = s.size();
        string ans = "";
        unordered_map<char,int> freq;
        for(int i = 0 ; i < n ; i++) freq[s[i]]++;

        for(int i = 0; i < n; i++){
            for(char c = 'a'; c <= 'z'; c++){
                if(freq[c] == 0) continue;

                ans.push_back(c);
                freq[c]--;

                string mini = ans + MinString(freq);
                string maxi = ans + MaxString(freq);

                if(target >= maxi){
                    ans.pop_back(); 
                    freq[c]++;
                    continue;
                } 
                else if(mini > target) {
                    return mini;
                } 
                else {
                    break;
                }
            }
        }
        if(ans == target) return "";
        return ans;
    }
};

int main() {
    Solution sol;
    string s, target;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter target string: ";
    cin >> target;

    string result = sol.nextGreaterPermutation(s, target);
    if(result == "") cout << "No lexicographically greater permutation possible.\n";
    else cout << "Answer: " << result << endl;

    return 0;
}
