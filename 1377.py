from typing import *

    
class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        def dfs(u, parent, p_, t):
            # u: current node
            # p: probability visiting u at current time, each child has 1/(num of children) probability
            # t: time left
            # return when target is reached or time runs out
            nonlocal prob
            if u == target:
                prob = p_
                if t and len(g[u]) > 1:
                    prob = 0
                return True
            if t == 0:
                return False
            for v in g[u]:
                if v == parent:
                    continue
                target_reached = dfs(v, u, p_ * (len(g[u]) - 1), t-1)
                if target_reached:
                    return True
            return False
         
        prob = 0
        g = [[] for _ in range(n+1)]
        g[1] = [0]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        dfs(1, 0, 1, t)
        return 1/prob if prob else 0
        



def main():
    sol = Solution()
    res = sol.foo()
    print(res)

main()