class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = set()
        prev = set()
        for num in arr:
            cur = {num}
            for val in prev:
                cur.add(val | num)
            res.update(cur)
            prev = cur
        return len(res)
        