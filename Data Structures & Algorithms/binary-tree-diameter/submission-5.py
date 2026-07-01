# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        max_d = 0
        def hight(node):
            nonlocal max_d
            if not node: return 0

            left = hight(node.left)
            right = hight(node.right)
            max_d = max(left+right,max_d)

            return max(left,right) + 1

        hight(root)

        return max_d