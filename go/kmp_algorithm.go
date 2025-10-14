/**
 * KMP (Knuth-Morris-Pratt) String Matching Algorithm Implementation
 * 
 * Problem: Pattern Matching in Text
 * Source: Classic String Matching Algorithm
 * Approach: Preprocessing pattern to create failure function (LPS array)
 * Time Complexity: O(n + m) where n is text length, m is pattern length
 * Space Complexity: O(m) for LPS array
 * 
 * The KMP algorithm uses the failure function to avoid unnecessary comparisons
 * by utilizing information from previous matches.
 */

package main

import (
	"fmt"
	"strings"
)

// KMPStringMatcher implements the Knuth-Morris-Pratt algorithm
type KMPStringMatcher struct {
	pattern string
	lps     []int // Longest Proper Prefix which is also Suffix
}

// NewKMPStringMatcher creates a new KMP matcher for the given pattern
func NewKMPStringMatcher(pattern string) *KMPStringMatcher {
	kmp := &KMPStringMatcher{
		pattern: pattern,
		lps:     make([]int, len(pattern)),
	}
	kmp.preprocessPattern()
	return kmp
}

// preprocessPattern creates the LPS (Longest Proper Prefix which is also Suffix) array
func (kmp *KMPStringMatcher) preprocessPattern() {
	pattern := kmp.pattern
	m := len(pattern)
	
	if m == 0 {
		return
	}
	
	// lps[0] is always 0
	kmp.lps[0] = 0
	
	length := 0 // length of the previous longest prefix suffix
	i := 1
	
	// Fill lps[i] for i = 1 to m-1
	for i < m {
		if pattern[i] == pattern[length] {
			length++
			kmp.lps[i] = length
			i++
		} else {
			// This is tricky. Consider the example:
			// AAACAAAA and i = 7. The idea is similar to search step.
			if length != 0 {
				length = kmp.lps[length-1]
				// Also, note that we do not increment i here
			} else {
				kmp.lps[i] = 0
				i++
			}
		}
	}
}

// Search finds all occurrences of pattern in text
func (kmp *KMPStringMatcher) Search(text string) []int {
	var result []int
	n := len(text)
	m := len(kmp.pattern)
	
	if m == 0 || m > n {
		return result
	}
	
	i := 0 // index for text
	j := 0 // index for pattern
	
	for i < n {
		if kmp.pattern[j] == text[i] {
			i++
			j++
		}
		
		if j == m {
			// Pattern found at position i-j
			result = append(result, i-j)
			j = kmp.lps[j-1]
		} else if i < n && kmp.pattern[j] != text[i] {
			// Mismatch after j matches
			if j != 0 {
				j = kmp.lps[j-1]
			} else {
				i++
			}
		}
	}
	
	return result
}

// SearchFirst finds the first occurrence of pattern in text
func (kmp *KMPStringMatcher) SearchFirst(text string) int {
	positions := kmp.Search(text)
	if len(positions) > 0 {
		return positions[0]
	}
	return -1
}

// Count counts the number of occurrences of pattern in text
func (kmp *KMPStringMatcher) Count(text string) int {
	return len(kmp.Search(text))
}

// PrintLPS prints the LPS array for debugging
func (kmp *KMPStringMatcher) PrintLPS() {
	fmt.Printf("Pattern: %s\n", kmp.pattern)
	fmt.Printf("LPS:     %v\n", kmp.lps)
	
	// Visual representation
	fmt.Println("Index:   ", strings.Repeat(" ", len(kmp.pattern)))
	for i := 0; i < len(kmp.pattern); i++ {
		fmt.Printf("%d ", i)
	}
	fmt.Println()
}

// KMPSearch is a standalone function for quick searches
func KMPSearch(text, pattern string) []int {
	kmp := NewKMPStringMatcher(pattern)
	return kmp.Search(text)
}

// KMPFirstSearch is a standalone function for finding first occurrence
func KMPFirstSearch(text, pattern string) int {
	kmp := NewKMPStringMatcher(pattern)
	return kmp.SearchFirst(text)
}

// KMPCount is a standalone function for counting occurrences
func KMPCount(text, pattern string) int {
	kmp := NewKMPStringMatcher(pattern)
	return kmp.Count(text)
}

// AdvancedKMP provides additional functionality
type AdvancedKMP struct {
	*KMPStringMatcher
	caseSensitive bool
}

// NewAdvancedKMP creates an advanced KMP matcher with options
func NewAdvancedKMP(pattern string, caseSensitive bool) *AdvancedKMP {
	if !caseSensitive {
		pattern = strings.ToLower(pattern)
	}
	
	return &AdvancedKMP{
		KMPStringMatcher: NewKMPStringMatcher(pattern),
		caseSensitive:     caseSensitive,
	}
}

// SearchCaseInsensitive searches for pattern in text (case insensitive)
func (akmp *AdvancedKMP) SearchCaseInsensitive(text string) []int {
	if akmp.caseSensitive {
		return akmp.Search(text)
	}
	
	lowerText := strings.ToLower(text)
	return akmp.Search(lowerText)
}

// SearchWithContext finds pattern and returns matches with surrounding context
func (akmp *AdvancedKMP) SearchWithContext(text string, contextLength int) []MatchWithContext {
	var result []MatchWithContext
	positions := akmp.Search(text)
	
	for _, pos := range positions {
		start := max(0, pos-contextLength)
		end := min(len(text), pos+len(akmp.pattern)+contextLength)
		context := text[start:end]
		
		result = append(result, MatchWithContext{
			Position: pos,
			Match:    text[pos : pos+len(akmp.pattern)],
			Context:  context,
		})
	}
	
	return result
}

// MatchWithContext represents a match with surrounding context
type MatchWithContext struct {
	Position int
	Match    string
	Context  string
}

// Utility functions
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Demo function to test KMP algorithm
func main() {
	fmt.Println("=== KMP (Knuth-Morris-Pratt) String Matching Algorithm ===\n")
	
	// Test cases
	testCases := []struct {
		text    string
		pattern string
	}{
		{"ABABDABACDABABCABAB", "ABABCABAB"},
		{"THIS IS A TEST TEXT", "TEST"},
		{"AABAACAADAABAABA", "AABA"},
		{"GEEKS FOR GEEKS", "GEEK"},
		{"AAAAAAAAAAAAAAAAAA", "AAAA"},
		{"", "PATTERN"},
		{"TEXT", ""},
		{"", ""},
		{"ababababab", "abab"},
		{"mississippi", "issi"},
	}
	
	for i, tc := range testCases {
		fmt.Printf("Test Case %d:\n", i+1)
		fmt.Printf("Text: \"%s\"\n", tc.text)
		fmt.Printf("Pattern: \"%s\"\n", tc.pattern)
		
		// Create KMP matcher
		kmp := NewKMPStringMatcher(tc.pattern)
		
		// Find all matches
		matches := kmp.Search(tc.text)
		fmt.Printf("Matches found: %d\n", len(matches))
		
		if len(matches) > 0 {
			fmt.Printf("Positions: %v\n", matches)
			for _, pos := range matches {
				fmt.Printf("  Match at %d: \"%s\"\n", pos, tc.text[pos:pos+len(tc.pattern)])
			}
		} else {
			fmt.Println("Pattern not found")
		}
		
		// Show LPS array for non-empty patterns
		if len(tc.pattern) > 0 {
			fmt.Println("LPS Array:")
			kmp.PrintLPS()
		}
		
		fmt.Println(strings.Repeat("-", 50))
	}
	
	// Performance comparison
	fmt.Println("\n=== Performance Comparison ===")
	largeText := strings.Repeat("A", 10000) + "B" + strings.Repeat("A", 10000)
	largePattern := strings.Repeat("A", 100) + "B"
	
	// KMP
	kmp := NewKMPStringMatcher(largePattern)
	matches := kmp.Search(largeText)
	fmt.Printf("KMP - Text length: %d, Pattern length: %d\n", len(largeText), len(largePattern))
	fmt.Printf("KMP - Matches found: %d\n", len(matches))
	
	// Naive string search for comparison
	naiveMatches := 0
	for i := 0; i <= len(largeText)-len(largePattern); i++ {
		if largeText[i:i+len(largePattern)] == largePattern {
			naiveMatches++
		}
	}
	fmt.Printf("Naive - Matches found: %d\n", naiveMatches)
	
	// Advanced KMP features
	fmt.Println("\n=== Advanced KMP Features ===")
	advancedKMP := NewAdvancedKMP("test", false) // case insensitive
	text := "This is a TEST text with Test and test"
	
	fmt.Printf("Text: \"%s\"\n", text)
	fmt.Printf("Pattern: \"test\" (case insensitive)\n")
	
	matchesWithContext := advancedKMP.SearchWithContext(text, 5)
	for _, match := range matchesWithContext {
		fmt.Printf("Match at %d: \"%s\" | Context: \"%s\"\n", 
			match.Position, match.Match, match.Context)
	}
	
	// LPS array visualization
	fmt.Println("\n=== LPS Array Visualization ===")
	patterns := []string{"ABABCABAB", "AAAA", "ABCDE", "AABAACAABAA"}
	
	for _, pattern := range patterns {
		kmp := NewKMPStringMatcher(pattern)
		fmt.Printf("\nPattern: %s\n", pattern)
		kmp.PrintLPS()
		
		// Visual explanation
		fmt.Println("Explanation:")
		for i := 0; i < len(pattern); i++ {
			if kmp.lps[i] > 0 {
				fmt.Printf("  Position %d: LPS[%d] = %d (longest proper prefix-suffix of length %d)\n", 
					i, i, kmp.lps[i], kmp.lps[i])
			}
		}
	}
}
