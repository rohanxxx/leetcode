# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return list()
        
        ans = []
        dq = deque([root])
        while(len(dq)):
            levelSize = len(dq)
            levelList = []
            for i in range(levelSize):
                node = dq.popleft()
                if node.left is not None:
                    dq.append(node.left)
                if node.right is not None:
                    dq.append(node.right)
                levelList.append(node.val)
            ans.append(levelList)
        
        return ans