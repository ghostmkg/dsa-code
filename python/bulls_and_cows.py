from collections import defaultdict

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0

        secret_count = defaultdict(int)
        guess_count = defaultdict(int)

        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
            else:
                secret_count[s] += 1
                guess_count[g] += 1

        for digit in guess_count:
            cows += min(secret_count[digit], guess_count[digit])

        return f"{bulls}A{cows}B"
