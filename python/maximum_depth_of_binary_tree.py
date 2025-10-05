class Solution(object):
    def maxDepth(self, root):
        
        if not root:
            return 0
        def m(node):
            if not node:
                return 0
            l=m(node.left)
            r=m(node.right)
            return 1+max(l,r)
        return m(root)
        
        