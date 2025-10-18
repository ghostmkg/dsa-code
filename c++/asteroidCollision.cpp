#include<bits/stdc++.h>
using namespace std;

//Problem: Leetcode 735 - Asteroid Collision
// Difficulty: Medium
// Approach: Stack simulation using vector
// Description:
// Stimulate collisions between moving asteroids.
// Positive values move right, negative values move left.
// Collisions occur when a positive asteroid meets a negative one.

// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    vector<int> arr;

    for(int i=0;i<n;i++){
        if(asteroids[i]>0){
            arr.push_back(asteroids[i]);
        }

        else{
            while(!arr.empty() && arr.back()>0 && arr.back()<abs(asteroids[i])){
                arr.pop_back();
            }

            if(!arr.empty() && arr.back()==abs(asteroids[i])){
                arr.pop_back();
            }
            else if(arr.empty() || arr.back()<0){
                arr.push_back(asteroids[i]);
            }
        }
    }
    return arr;
}

int main(){

    vector<int> asteroids = {-4, -1, 10, 2, -1, 8, -9, -6, 5, 2};
    cout << "Initial Asteroids: ";
    for (int i=0;i<asteroids.size();i++){
        cout <<asteroids[i]<< " ";
    }
    cout << endl;
    vector<int> ans = asteroidCollision(asteroids);

    cout << "Result after collisions: ";
    for (int i=0;i<ans.size();i++){
        cout <<ans[i]<< " ";
    }
    cout << endl;

    return 0;
}