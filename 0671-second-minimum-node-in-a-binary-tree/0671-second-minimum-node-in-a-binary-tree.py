# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs (self, root, list_set):
        if not root:
            return
        list_set.add(root.val)
        self.dfs(root.left, list_set)
        self.dfs(root.right, list_set)
    
    def findSecondMinimumValue(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        list_set = set()
        self.dfs(root, list_set)

        #sorted(list_set)

        if len(list_set) < 2:
            return -1
        
        return sorted(list_set)[1]
        