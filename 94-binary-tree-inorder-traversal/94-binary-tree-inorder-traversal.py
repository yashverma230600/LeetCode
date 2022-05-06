class Solution:
    def inorderTraversal_(self, root):
        if root.left:
            self.inorderTraversal_(root.left)
        self.res.append(root.val)
        if root.right:
            self.inorderTraversal_(root.right)
    def inorderTraversal(self, root):
        self.res = []
        if root:
            self.inorderTraversal_(root)
        return self.res