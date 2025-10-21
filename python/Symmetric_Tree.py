class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def helper(pointer1, pointer2):
            if pointer1 is None and pointer2 is None:
                return True
            if pointer1 is None or pointer2 is None:
                return False
            if pointer1.val == pointer2.val:
                ans1 = helper(pointer1.left, pointer2.right)
                ans2 = helper(pointer1.right, pointer2.left)
                return ans1 and ans2
            else:
                return False

        return helper(root.left, root.right)