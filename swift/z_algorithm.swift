// Z-Algorithm Implementation in Swift
// The Z-algorithm computes the Z-array for a string, where Z[i] is the length of the longest substring
// starting at position i that matches the prefix of the string.
// This is useful for string pattern matching and other string algorithms.

import Foundation

func zAlgorithm(for string: String) -> [Int] {
    let chars = Array(string)
    let n = chars.count
    var z = [Int](repeating: 0, count: n)
    var l = 0
    var r = 0

    for i in 1..<n {
        if i < r {
            z[i] = min(r - i, z[i - l])
        }
        while i + z[i] < n && chars[z[i]] == chars[i + z[i]] {
            z[i] += 1
        }
        if i + z[i] > r {
            l = i
            r = i + z[i]
        }
    }
    return z
}

// Example usage
let inputString = "aabcaabxaaz"
let zArray = zAlgorithm(for: inputString)
print("Z-array for '\(inputString)': \(zArray)")

// Explanation:
// For string "aabcaabxaaz", the Z-array would be [0, 1, 0, 0, 3, 1, 0, 0, 2, 1, 0]
// Z[4] = 3 because "aab" matches the prefix "aab"
// Z[8] = 2 because "aa" matches the prefix "aa"
