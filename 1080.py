from typing import *


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
def print_tree(root: TreeNode):
    # print tree in bfs order and print new line for each level
    if not root:
        return
    q = [root]
    while q:
        n = len(q)
        for i in range(n):
            node = q.pop(0)
            print(node.val, end=' ')
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        print()
        

class Solution:
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        if not root:
            return None
        if not root.left and not root.right:
            if root.val < limit:
                return None
            else:
                return root
        root.left = self.sufficientSubset(root.left, limit - root.val)
        root.right = self.sufficientSubset(root.right, limit - root.val)
        if not root.left and not root.right:
            return None
        else:
            return root


def main():
    sol = Solution()
    root = TreeNode(1)
    root.left = TreeNode(-99)
    root.right = TreeNode(2)
    root.left.left = TreeNode(99)
    root.left.right = TreeNode(0)
    res = sol.sufficientSubset(root, 1)
    print_tree(res)

main()