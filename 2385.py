from typing import *
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# bfs
def build_tree(l_root):
    i = 1
    root = TreeNode(l_root[0])
    dq_node = deque([root])
    while i < len(l_root):
        parent = dq_node.popleft()
        if l_root[i] != -1:
            left_c = TreeNode(l_root[i])
            parent.left = left_c
            dq_node.append(left_c)
        i += 1
        if i >= len(l_root):
            break
        if l_root[i] != -1:
            right_c = TreeNode(l_root[i])
            parent.right = right_c
            dq_node.append(right_c)
        i += 1
    dq_node.clear()
    return root

def print_tree(root: TreeNode):
    dq_node = deque([root])
    l_root = []
    while dq_node:
        parent = dq_node.popleft()
        l_root.append(parent.val)
        if parent.left is None and parent.right is None:
            continue
        elif parent.left is None:
            dq_node.append(TreeNode(-1))
            dq_node.append(parent.right)
        elif parent.right is None:
            dq_node.append(parent.left)
            dq_node.append(TreeNode(-1))
        else:
            dq_node.append(parent.left)
            dq_node.append(parent.right)
    print(l_root)


class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int: 
        # parents of START
        # distance to START add the depth of other branch

        def dfs(root: TreeNode) -> Tuple:
            nonlocal res
            if not root:
                return -1, 0
            # left
            ldis, ld = dfs(root.left)
            # right
            rdis, rd = dfs(root.right)
            depth = max(ld, rd)
            dis = -1
            if root.val == start:
                res = max(res, depth)
                return 0, depth+1
            if ldis >= 0:
                dis = ldis+1
                res = max(res, dis+rd)
            elif rdis >= 0:
                dis = rdis+1
                res = max(res, dis+ld)
            return dis, depth+1
        
        res = 0
        dfs(root)
        return res
   

def main():
    sol = Solution()
    l_root = [1,5,3,-1,4,10,6,9,2]
    root = build_tree(l_root)
    # print_tree(root)
    start = 3
    res = sol.amountOfTime(root, start)
    print(res)

main()