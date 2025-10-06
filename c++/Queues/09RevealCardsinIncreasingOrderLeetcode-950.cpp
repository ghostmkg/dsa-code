#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           int idx= q.front();
           q.pop();
           q.push(q.front());
           q.pop();
           ans[idx]=deck[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
    std::vector<int> result1 = sol.deckRevealedIncreasing(deck1);

    std::cout << "Deck: ";
    for (int card : deck1) {
        std::cout << card << " ";
    }
    std::cout << "\nRevealed Order: ";
    for (int card : result1) {
        std::cout << card << " ";
    }
    std::cout << std::endl;

    return 0;
}