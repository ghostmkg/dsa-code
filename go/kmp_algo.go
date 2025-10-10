package main

import "fmt"

// Build LPS (Longest Prefix Suffix) array
func buildLPS(pattern string) []int {
    m := len(pattern)
    lps := make([]int, m)
    length := 0
    i := 1

    for i < m {
        if pattern[i] == pattern[length] {
            length++
            lps[i] = length
            i++
        } else {
            if length != 0 {
                length = lps[length-1]
            } else {
                lps[i] = 0
                i++
            }
        }
    }
    return lps
}

// KMP search algorithm
func kmpSearch(text, pattern string) {
    n := len(text)
    m := len(pattern)
    lps := buildLPS(pattern)

    i, j := 0, 0 // i -> text, j -> pattern

    for i < n {
        if text[i] == pattern[j] {
            i++
            j++
        }

        if j == m {
            fmt.Printf("Pattern found at index %d\n", i-j)
            j = lps[j-1] // Continue searching
        } else if i < n && text[i] != pattern[j] {
            if j != 0 {
                j = lps[j-1]
            } else {
                i++
            }
        }
    }
}

func main() {
    text := "ABABDABACDABABCABAB"
    pattern := "ABABCABAB"

    kmpSearch(text, pattern)
}
