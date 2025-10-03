/**
 * @file KMPStringMatching.cpp
 * @brief Implementation of Knuth-Morris-Pratt (KMP) String Matching Algorithm
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Find all occurrences of a pattern string in a text string efficiently.
 *
 * Algorithm: KMP Pattern Matching
 * - Preprocess pattern to build LPS (Longest Proper Prefix which is also Suffix) array
 * - Use LPS array to avoid unnecessary comparisons when mismatch occurs
 * - Never move back in the text, only adjust pattern position based on LPS
 *
 * Key Insight: When a mismatch occurs, use information from previous matches
 * to skip comparisons we know will match, based on pattern's prefix-suffix structure.
 *
 * Time Complexity: O(N + M) where N = text length, M = pattern length
 * Space Complexity: O(M) for LPS array
 *
 * Advantage over naive approach: No backtracking in text (O(N*M) -> O(N+M))
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP {
private:
    /**
     * @brief Compute LPS (Longest Proper Prefix which is also Suffix) array
     * @param pattern Pattern string to preprocess
     * @return LPS array where lps[i] = length of longest proper prefix of pattern[0..i]
     *                                   which is also a suffix of pattern[0..i]
     *
     * Example: For pattern "ABABC"
     * Index:     0  1  2  3  4
     * Pattern:   A  B  A  B  C
     * LPS:       0  0  1  2  0
     *
     * Explanation:
     * - lps[0] = 0 (single character has no proper prefix)
     * - lps[1] = 0 ("AB" has no matching prefix-suffix)
     * - lps[2] = 1 ("ABA": "A" is both prefix and suffix)
     * - lps[3] = 2 ("ABAB": "AB" is both prefix and suffix)
     * - lps[4] = 0 ("ABABC" has no matching prefix-suffix)
     *
     * Time Complexity: O(M) where M is pattern length
     */
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);

        int len = 0;  // Length of previous longest prefix suffix
        int i = 1;    // Start from index 1 (lps[0] is always 0)

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                // Characters match - extend the prefix
                len++;
                lps[i] = len;
                i++;
            } else {
                // Mismatch after len matches
                if (len != 0) {
                    // Try shorter prefix (don't increment i, recheck with shorter prefix)
                    len = lps[len - 1];
                } else {
                    // No prefix found
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

public:
    /**
     * @brief Search for all occurrences of pattern in text using KMP algorithm
     * @param text Text string to search in
     * @param pattern Pattern string to search for
     * @return Vector of starting indices where pattern is found in text
     *
     * Algorithm:
     * 1. Compute LPS array for pattern
     * 2. Use two pointers: i for text, j for pattern
     * 3. When match: increment both pointers
     * 4. When mismatch:
     *    - If j != 0: use LPS to skip unnecessary comparisons (j = lps[j-1])
     *    - If j == 0: move to next character in text (i++)
     * 5. When full pattern matched: record index, use LPS to continue searching
     *
     * Time Complexity: O(N + M)
     */
    vector<int> search(const string& text, const string& pattern) {
        vector<int> result;

        if (pattern.empty() || text.empty() || pattern.length() > text.length()) {
            return result;  // No matches possible
        }

        int n = text.length();
        int m = pattern.length();

        // Preprocess pattern to get LPS array
        vector<int> lps = computeLPS(pattern);

        int i = 0;  // Index for text
        int j = 0;  // Index for pattern

        while (i < n) {
            if (text[i] == pattern[j]) {
                // Characters match - move both pointers
                i++;
                j++;
            }

            if (j == m) {
                // Full pattern matched
                result.push_back(i - j);  // Record starting index

                // Continue searching for more occurrences
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                // Mismatch after j matches
                if (j != 0) {
                    // Use LPS to avoid re-matching prefix
                    j = lps[j - 1];
                } else {
                    // No prefix to fall back to, move to next char in text
                    i++;
                }
            }
        }

        return result;
    }

    /**
     * @brief Search with detailed step-by-step output (for educational purposes)
     * @param text Text string to search in
     * @param pattern Pattern string to search for
     * @return Vector of starting indices where pattern is found
     */
    vector<int> searchVerbose(const string& text, const string& pattern) {
        vector<int> result;

        cout << "\n=== KMP Search Process ===" << endl;
        cout << "Text:    " << text << endl;
        cout << "Pattern: " << pattern << endl;

        int n = text.length();
        int m = pattern.length();

        // Compute and display LPS array
        vector<int> lps = computeLPS(pattern);
        cout << "\nLPS Array: [";
        for (int i = 0; i < lps.size(); i++) {
            cout << lps[i];
            if (i < lps.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        cout << "\nMatching Process:" << endl;

        int i = 0, j = 0;
        int step = 0;

        while (i < n) {
            step++;
            cout << "Step " << step << ": text[" << i << "]='" << text[i]
                 << "' vs pattern[" << j << "]='" << pattern[j] << "' ";

            if (text[i] == pattern[j]) {
                cout << "-> Match!" << endl;
                i++;
                j++;
            } else {
                cout << "-> Mismatch!" << endl;
            }

            if (j == m) {
                cout << "  *** Pattern found at index " << (i - j) << " ***" << endl;
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    cout << "  Using LPS: j = lps[" << (j - 1) << "] = " << lps[j - 1] << endl;
                    j = lps[j - 1];
                    step--;  // Don't count as step since i doesn't move
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    /**
     * @brief Print LPS array with explanation
     * @param pattern Pattern string
     */
    void printLPS(const string& pattern) {
        vector<int> lps = computeLPS(pattern);

        cout << "\nPattern: " << pattern << endl;
        cout << "Index:   ";
        for (int i = 0; i < pattern.length(); i++) {
            cout << i << " ";
        }
        cout << endl;

        cout << "Char:    ";
        for (char c : pattern) {
            cout << c << " ";
        }
        cout << endl;

        cout << "LPS:     ";
        for (int val : lps) {
            cout << val << " ";
        }
        cout << endl;
    }

    /**
     * @brief Count total occurrences of pattern in text
     * @param text Text string
     * @param pattern Pattern string
     * @return Number of occurrences
     */
    int countOccurrences(const string& text, const string& pattern) {
        return search(text, pattern).size();
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    KMP kmp;

    // Test case 1: Multiple occurrences
    cout << "=== Test Case 1: Multiple Occurrences ===" << endl;
    string text1 = "ABABDABACDABABCABAB";
    string pattern1 = "ABAB";

    vector<int> matches1 = kmp.search(text1, pattern1);
    cout << "Text:    " << text1 << endl;
    cout << "Pattern: " << pattern1 << endl;
    cout << "Found at indices: ";
    for (int idx : matches1) {
        cout << idx << " ";
    }
    cout << endl;

    // Test case 2: With verbose output
    cout << "\n=== Test Case 2: Verbose Search ===" << endl;
    string text2 = "AABAACAADAABAABA";
    string pattern2 = "AABA";
    vector<int> matches2 = kmp.searchVerbose(text2, pattern2);

    // Test case 3: Pattern not found
    cout << "\n=== Test Case 3: Pattern Not Found ===" << endl;
    string text3 = "ABCDEFGH";
    string pattern3 = "XYZ";
    vector<int> matches3 = kmp.search(text3, pattern3);
    cout << "Text:    " << text3 << endl;
    cout << "Pattern: " << pattern3 << endl;
    if (matches3.empty()) {
        cout << "Pattern not found" << endl;
    }

    // Test case 4: LPS demonstration
    cout << "\n=== Test Case 4: LPS Array Examples ===" << endl;
    kmp.printLPS("ABABCABAB");
    kmp.printLPS("AAAA");
    kmp.printLPS("ABCDE");
    kmp.printLPS("AABAACAABAA");

    // Test case 5: Count occurrences
    cout << "\n=== Test Case 5: Count Occurrences ===" << endl;
    string text5 = "AAAAAAA";
    string pattern5 = "AA";
    int count = kmp.countOccurrences(text5, pattern5);
    cout << "Text:    " << text5 << endl;
    cout << "Pattern: " << pattern5 << endl;
    cout << "Total occurrences: " << count << endl;

    return 0;
}
