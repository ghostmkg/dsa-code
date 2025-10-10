//C++ program to reverse words in a string
Time Complexity: O(n)
Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;        

int main() {
    string s; // Input string   
    getline(cin, s); // Read the entire line including spaces
    stringstream ss(s); // Use stringstream to split the string
    string word;
    vector<string> words;

    // Split the string into words
    while (ss >> word) {
        words.push_back(word); // Store each word in a vector
    }

    // Reverse the order of words in
    reverse(words.begin(), words.end());

    // Join the words back into a single string
    string reversedString;
    for (size_t i = 0; i < words.size(); ++i) {
        reversedString += words[i];
        if (i != words.size() - 1) {
            reversedString += " "; // Add space between words
        }
    }

    cout << reversedString << endl; // Output the reversed string
    return 0;
}