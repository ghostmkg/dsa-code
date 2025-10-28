# Problem: DNA Sequence Pattern Finder using KMP + Rabin-Karp Hybrid

# Description:
# Efficiently finds all occurrences of a DNA sequence pattern (substring)
# within a longer DNA string using a hybrid of Rabin-Karp (for hashing) 
# and KMP (for prefix optimization).

# Why hybrid? 
# Rabin-Karp provides fast rolling hash comparisons.
# KMP ensures correctness by avoiding false positives from hash collisions.

# Example use-cases:
# Genome research: searching for specific gene patterns in DNA sequences.
# Bioinformatics pipelines: DNA motif detection.

BASE = 4  # DNA alphabet size: A, C, G, T
MOD = 10**9 + 7

# Map DNA characters to numbers
DNA_MAP = {'A': 0, 'C': 1, 'G': 2, 'T': 3}

def rabin_karp_hash(s):
    """Compute hash for a DNA sequence string."""
    h = 0
    for ch in s:
        h = (h * BASE + DNA_MAP[ch]) % MOD
    return h


def compute_lps(pattern):
    """Compute Longest Prefix Suffix (LPS) array for KMP algorithm."""
    lps = [0] * len(pattern)
    length = 0
    i = 1
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps


def dna_pattern_finder(text, pattern):
    """
    Hybrid algorithm to find all occurrences of 'pattern' in 'text'.
    Uses Rabin-Karp for fast hash matching + KMP for exact validation.
    """
    if len(pattern) == 0 or len(text) < len(pattern):
        return []

    m, n = len(pattern), len(text)
    pattern_hash = rabin_karp_hash(pattern)
    current_hash = rabin_karp_hash(text[:m])
    positions = []

    power = pow(BASE, m - 1, MOD)  # precompute power for rolling hash
    lps = compute_lps(pattern)

    for i in range(n - m + 1):
        if i > 0:
            # Roll the hash
            current_hash = (
                (current_hash - DNA_MAP[text[i - 1]] * power) * BASE + DNA_MAP[text[i + m - 1]]
            ) % MOD

        # Hash match — verify with KMP-like check
        if current_hash == pattern_hash:
            j = 0
            k = i
            while j < m and k < n and text[k] == pattern[j]:
                j += 1
                k += 1
            if j == m:
                positions.append(i)

    return positions


if __name__ == "__main__":
    # Example DNA sequence and pattern
    dna_sequence = "ACGTACGTGACGTTACG"
    pattern = "ACGT"

    result = dna_pattern_finder(dna_sequence, pattern)
    print(f"DNA Sequence: {dna_sequence}")
    print(f"Pattern: {pattern}")
    print(f"Occurrences found at indices: {result}")
