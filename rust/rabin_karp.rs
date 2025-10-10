fn rabin_karp(text: &str, pattern: &str) {
    let d: u64 = 256;        // Number of characters in input alphabet
    let q: u64 = 101;        // A prime number for modulo
    let m = pattern.len();
    let n = text.len();

    if m > n {
        println!("Pattern is longer than text — no match.");
        return;
    }

    let text_bytes = text.as_bytes();
    let pattern_bytes = pattern.as_bytes();

    let mut p: u64 = 0; // hash for pattern
    let mut t: u64 = 0; // hash for text window
    let mut h: u64 = 1; // d^(m-1) % q

    // Precompute h = pow(d, m-1) % q
    for _ in 0..m - 1 {
        h = (h * d) % q;
    }

    // Compute initial hash values for pattern and first window
    for i in 0..m {
        p = (d * p + pattern_bytes[i] as u64) % q;
        t = (d * t + text_bytes[i] as u64) % q;
    }

    // Slide the pattern over the text
    for i in 0..=(n - m) {
        // Check if hashes match
        if p == t {
            // Double-check characters
            if &text[i..i + m] == pattern {
                println!("Pattern found at index {}", i);
            }
        }

        // Compute hash for next window
        if i < n - m {
            t = (d * (t + q - (text_bytes[i] as u64 * h) % q) + text_bytes[i + m] as u64) % q;
        }
    }
}

fn main() {
    let text = "ABCCDDAEFG";
    let pattern = "CDD";

    rabin_karp(text, pattern);
}
