class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        result = int("".join(map(str, digits)))
        result = result + 1
        re = list(map(int, str(result)))
        return re