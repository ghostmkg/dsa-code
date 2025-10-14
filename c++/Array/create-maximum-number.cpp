// Intuition
// We need to form the maximum possible number of length k by selecting digits from two arrays nums1 and nums2.
// The tricky part is that we must keep the relative order of digits in each array, but can interleave the two sequences freely.

class Solution
{
public:
  // Helper function to pick the largest possible subsequence
  // of a given length from 'num' using a greedy stack approach.
  vector<int> removeKdigits(vector<int> &num, int k)
  {
    int n = num.size();
    if (k == 0)
      return num; // if nothing to remove, just return the array

    stack<int> st;
    st.push(num[0]);

    // Traverse through all digits
    for (int i = 1; i < n; i++)
    {
      // If the current digit is larger than the top of stack and we can remove more,
      // pop smaller digits to make room for a larger one (maximize lexicographic order)
      while (!st.empty() && k > 0 && st.top() < num[i])
      {
        st.pop();
        k--;
      }
      st.push(num[i]);
    }

    // If we still have digits left to remove, remove from the end (least significant)
    while (k > 0 && !st.empty())
    {
      st.pop();
      k--;
    }

    // Convert stack to vector (in correct order)
    vector<int> ans;
    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  // Lexicographic comparison between two remaining suffixes of arrays a[i:] and b[j:].
  // Returns true if a[i:] >= b[j:].
  bool lexCompare(vector<int> &a, int i, vector<int> &b, int j)
  {
    int n = a.size(), m = b.size();
    // Move forward while both digits are same
    while (i < n && j < m && a[i] == b[j])
    {
      i++;
      j++;
    }
    // If b is exhausted, a is lexicographically greater or equal
    if (j == m)
      return true;
    // If a is exhausted first, it's smaller
    if (i == n)
      return false;
    // Otherwise, whichever has the larger next digit wins
    return a[i] > b[j];
  }

  // Merges two subsequences into one final sequence
  // by always choosing the lexicographically larger remaining suffix.
  vector<int> merge(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    int l = 0, r = 0;
    vector<int> temp;

    // Merge like in merge-sort, but lexicographically
    while (l < n || r < m)
    {
      if (lexCompare(nums1, l, nums2, r))
      {
        temp.push_back(nums1[l++]); // pick from nums1 if it's lexicographically larger
      }
      else
      {
        temp.push_back(nums2[r++]); // else pick from nums2
      }
    }
    return temp;
  }

  // Main function to form the maximum number of length 'k'
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> ans;

    // Try all possible ways to split k between nums1 and nums2
    // k1 digits from nums1 and k2 = k - k1 digits from nums2
    for (int k1 = max(0, k - m); k1 <= min(k, n); k1++)
    {
      int k2 = k - k1;

      // Get best subsequences from both arrays
      vector<int> t1 = removeKdigits(nums1, n - k1);
      vector<int> t2 = removeKdigits(nums2, m - k2);

      // Merge the two subsequences to form the final candidate
      vector<int> t = merge(t1, t2);

      // Store this candidate
      ans.push_back(t);
    }

    // Sort all candidates and return the lexicographically largest one
    sort(ans.begin(), ans.end());
    return ans.back();
  }
};
