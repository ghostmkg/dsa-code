/**
 * Boyer-Moore String Matching Algorithm Implementation
 * 
 * Problem: Pattern Matching in Text
 * Source: Classic String Matching Algorithm
 * Approach: Boyer-Moore with Bad Character and Good Suffix Rules
 * Time Complexity: O(n/m) best case, O(n*m) worst case
 * Space Complexity: O(σ) where σ is alphabet size
 * 
 * The Boyer-Moore algorithm is one of the most efficient string matching algorithms.
 * It uses two heuristics: Bad Character Rule and Good Suffix Rule.
 */

class BoyerMooreStringMatching {
    
    /**
     * Find all occurrences of pattern in text using Boyer-Moore algorithm
     * @param text The text to search in
     * @param pattern The pattern to search for
     * @return List of starting indices where pattern is found
     */
    fun boyerMooreSearch(text: String, pattern: String): List<Int> {
        val result = mutableListOf<Int>()
        val n = text.length
        val m = pattern.length
        
        if (m == 0) return result
        if (m > n) return result
        
        // Preprocess bad character rule
        val badChar = preprocessBadCharacter(pattern)
        
        // Preprocess good suffix rule
        val goodSuffix = preprocessGoodSuffix(pattern)
        
        var s = 0 // Shift of pattern with respect to text
        
        while (s <= n - m) {
            var j = m - 1
            
            // Keep reducing index j of pattern while characters of pattern
            // and text are matching at this shift s
            while (j >= 0 && pattern[j] == text[s + j]) {
                j--
            }
            
            // If the pattern is present at current shift, then j will become -1
            if (j < 0) {
                result.add(s)
                // Shift the pattern so that the next character in text
                // aligns with the last occurrence of it in pattern
                s += if (s + m < n) {
                    m - badChar[text[s + m].code] ?: -1
                } else 1
            } else {
                // Shift the pattern so that the bad character in text
                // aligns with the last occurrence of it in pattern
                val badCharShift = j - (badChar[text[s + j].code] ?: -1)
                val goodSuffixShift = goodSuffix[j]
                s += maxOf(badCharShift, goodSuffixShift)
            }
        }
        
        return result
    }
    
    /**
     * Preprocess bad character rule
     * Creates a map of character to its rightmost occurrence in pattern
     */
    private fun preprocessBadCharacter(pattern: String): Map<Int, Int> {
        val badChar = mutableMapOf<Int, Int>()
        
        for (i in pattern.indices) {
            badChar[pattern[i].code] = i
        }
        
        return badChar
    }
    
    /**
     * Preprocess good suffix rule
     * Creates an array where goodSuffix[i] is the shift distance
     * when mismatch occurs at position i
     */
    private fun preprocessGoodSuffix(pattern: String): IntArray {
        val m = pattern.length
        val goodSuffix = IntArray(m)
        val suffix = IntArray(m)
        
        // Case 1: Exact suffix match
        var i = m
        var j = m + 1
        suffix[i] = j
        
        while (i > 0) {
            while (j <= m && pattern[i - 1] != pattern[j - 1]) {
                if (goodSuffix[j] == 0) {
                    goodSuffix[j] = j - i
                }
                j = suffix[j]
            }
            i--
            j--
            suffix[i] = j
        }
        
        // Case 2: Partial suffix match
        j = suffix[0]
        for (i in 0..m) {
            if (goodSuffix[i] == 0) {
                goodSuffix[i] = j
            }
            if (i == j) {
                j = suffix[j]
            }
        }
        
        return goodSuffix
    }
    
    /**
     * Simplified Boyer-Moore using only bad character rule
     * This is easier to understand and implement
     */
    fun boyerMooreSimple(text: String, pattern: String): List<Int> {
        val result = mutableListOf<Int>()
        val n = text.length
        val m = pattern.length
        
        if (m == 0) return result
        if (m > n) return result
        
        // Preprocess bad character rule
        val badChar = preprocessBadCharacter(pattern)
        
        var s = 0 // Shift of pattern with respect to text
        
        while (s <= n - m) {
            var j = m - 1
            
            // Keep reducing index j of pattern while characters match
            while (j >= 0 && pattern[j] == text[s + j]) {
                j--
            }
            
            // If pattern is found
            if (j < 0) {
                result.add(s)
                // Shift pattern to align next character
                s += if (s + m < n) {
                    m - (badChar[text[s + m].code] ?: -1)
                } else 1
            } else {
                // Shift pattern using bad character rule
                val shift = j - (badChar[text[s + j].code] ?: -1)
                s += maxOf(1, shift)
            }
        }
        
        return result
    }
}

/**
 * Demo function to test Boyer-Moore algorithm
 */
fun main() {
    val bm = BoyerMooreStringMatching()
    
    // Test cases
    val testCases = listOf(
        Pair("ABAAABCD", "ABC"),
        Pair("GEEKS FOR GEEKS", "GEEK"),
        Pair("AABAACAADAABAABA", "AABA"),
        Pair("THIS IS A TEST TEXT", "TEST"),
        Pair("AAAAAAAAAAAAAAAAAA", "AAAA"),
        Pair("", "PATTERN"),
        Pair("TEXT", ""),
        Pair("", "")
    )
    
    println("=== Boyer-Moore String Matching Algorithm ===\n")
    
    testCases.forEach { (text, pattern) ->
        println("Text: \"$text\"")
        println("Pattern: \"$pattern\"")
        
        val result = bm.boyerMooreSearch(text, pattern)
        val simpleResult = bm.boyerMooreSimple(text, pattern)
        
        println("Full Boyer-Moore matches: $result")
        println("Simple Boyer-Moore matches: $simpleResult")
        
        if (result.isNotEmpty()) {
            println("Pattern found at positions: ${result.joinToString(", ")}")
            result.forEach { pos ->
                println("  Match: \"${text.substring(pos, pos + pattern.length)}\"")
            }
        } else {
            println("Pattern not found")
        }
        
        println("-".repeat(50))
    }
    
    // Performance comparison
    println("\n=== Performance Comparison ===")
    val largeText = "A".repeat(10000) + "B" + "A".repeat(10000)
    val largePattern = "A".repeat(100) + "B"
    
    val startTime = System.currentTimeMillis()
    val matches = bm.boyerMooreSearch(largeText, largePattern)
    val endTime = System.currentTimeMillis()
    
    println("Large text length: ${largeText.length}")
    println("Pattern length: ${largePattern.length}")
    println("Matches found: ${matches.size}")
    println("Time taken: ${endTime - startTime} ms")
}
