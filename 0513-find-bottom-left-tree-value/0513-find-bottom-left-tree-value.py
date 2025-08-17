# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return -1
        bottomLeft = -1
        
        dq = deque()
        dq.append(root)

        while dq:
            levelSize = len(dq)
            for i in range(levelSize):
                curNode = dq.popleft()
                if i == 0:
                    bottomLeft = curNode.val
                
                if curNode.left:
                    dq.append(curNode.left)
                if curNode.right:
                    dq.append(curNode.right)
        return bottomLeft

        