class Solution:
    def fib(self, n: int) -> int:
        from functools import lru_cache

        @lru_cache(None)
        def dfs(k: int) -> int:
            if k < 2:
                return k
            return dfs(k-1) + dfs(k-2)

        return dfs(n)

# test
if __name__ == "__main__":
    s = Solution()
    print(s.fib(30))  # 832040
