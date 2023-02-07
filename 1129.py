from typing import List
from collections import deque

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n)]
        dist = [[-1, -1] for _ in range(n)]
        for r0, r in redEdges:
            g[r0].append(r)
        for b0, b in blueEdges:
            g[b0].append(-b)
        q = deque([0])
        dist[0][0], dist[0][1] = 0, 0
        while q:
            fr = q.popleft()
            for v in g[fr]:
                color = 0
                if v < 0:
                    color = 1
                    v = -v
                d1 = dist[fr][1-color]+1
                if d1 == 0 or \
                   dist[v][color] != -1 and d1 >= dist[v][color]:
                   continue
                dist[v][color] = d1
                q.append(v)
        res = []
        for d0, d1 in dist:
            if d0 == -1 or d1 != -1 and d0 > d1:
                res.append(d1)
            else:
                 res.append(d0)
        return res


def main():
    sol = Solution()
    n = 3
    red_edges = [[0,1],[0,2]]
    blue_edges = [[1,0]]
    res = sol.shortestAlternatingPaths(n, red_edges, blue_edges)
    print(res)

main()