
class Solution(object):
    def isLeaf(self, t):
        return t.left == None and t.right == None

    def addLeaves(self, res, root):
        if self.isLeaf(root):
            res.append(root.val)
        else:
            if root.left != None:
                self.addLeaves(res, root.left)
            if root.right != None:
                self.addLeaves(res, root.right)

    def boundaryOfBinaryTree(self, root):
        if root == None:
            return []

        res = []
        if not self.isLeaf(root):
            res.append(root.val)

        # Add left boundary (excluding leaves)
        t = root.left
        while t != None:
            if not self.isLeaf(t):
                res.append(t.val)
            if t.left != None:
                t = t.left
            else:
                t = t.right

        # Add all leaf nodes
        self.addLeaves(res, root)

        # Add right boundary (excluding leaves) in reverse order
        stack = []
        t = root.right
        while t is not None:
            if not self.isLeaf(t):
                stack.append(t.val)
            if t.right != None:
                t = t.right
            else:
                t = t.left

        while stack:
            res.append(stack.pop())

        return res