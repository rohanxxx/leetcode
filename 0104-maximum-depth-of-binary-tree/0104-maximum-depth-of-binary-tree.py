# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        return 1 + max(self.dfs(root.left), self.dfs(root.right))
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)
        