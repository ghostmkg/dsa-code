from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordset = set(wordList)
        if endWord not in wordset:
            return 0

        q = deque([(beginWord, 1)])

        while q:
            word, steps = q.popleft()

            if word == endWord:
                return steps

            for i in range(len(word)):
                for ch in range(26):
                    transformed = word[:i] + chr(ord('a') + ch) + word[i+1:]
                    if transformed in wordset:
                        wordset.remove(transformed)
                        q.append((transformed, steps + 1))
        return 0