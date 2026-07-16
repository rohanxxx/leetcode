# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, prevNode: Optional[TreeNode], root: Optional[TreeNode], parentMap: Dict[int, Optional[TreeNode]], p: int) -> Optional[TreeNode]:
        if root == None:
            return None
        parentMap[root.val] = prevNode
        checkLeft = self.dfs(root, root.left, parentMap, p)
        checkRight = self.dfs(root, root.right, parentMap, p)
        
        if root.val == p:
            return root
    
        if checkLeft == None:
            return checkRight
        else:
            return checkLeft
    def bfs(self, node: Optional[TreeNode], parentMap: Dict[int, Optional[TreeNode]], dest: int)->int:
        q = deque()
        q.append([node, None])

        count = 0
        while len(q) > 0:
            levelSize = len(q)
            for i in range(levelSize):
                curNode, prevNode = q.popleft()
                if curNode.val == dest:
                    return count
                
                #traverse 
                if curNode.left != None:
                    q.append([curNode.left, curNode])
                if curNode.right != None:
                    q.append([curNode.right, curNode])
                #traverse it to parent
                if parentMap[curNode.val] != None and  parentMap[curNode.val] != prevNode:
                    q.append([parentMap[curNode.val], curNode])
            
            count += 1
        

        return 0
                



    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        # step 1 -> traverse whole tree and mark each nodes parents
        # step 2 -> traverse to pivot node
        parentMap: Dict[int, Optional[TreeNode]] = {}
        pivotNode = self.dfs(None, root, parentMap, p)
        # step 3 -> from the pivot node do the traversing to the destination
        return self.bfs(pivotNode, parentMap, q)
