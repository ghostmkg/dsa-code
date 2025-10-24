class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
            ret=[]
            while matrix:
                ret+=(matrix.pop(0))

                if matrix and matrix[0]:
                    for i in matrix :
                        ret.append(i.pop())
                if matrix:
                    ret+=(matrix.pop()[::-1])
                if matrix and matrix[0]:
                    for i in matrix[::-1]:
                        ret.append(i.pop(0))
            return ret

            