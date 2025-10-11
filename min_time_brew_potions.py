class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        done = [0] * (n + 1)
        
        for j in range(m):
            for i in range(n):
                done[i + 1] = max(done[i + 1], done[i]) + mana[j] * skill[i]
            for i in range(n - 1, 0, -1):
                done[i] = done[i + 1] - mana[j] * skill[i]
                
        return done[n]
