from typing import *


class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]
        self.count = n

    def find(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.count -= 1

    def is_connected(self, x, y):
        return self.find(x) == self.find(y) 
     
    
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        # union find
        n = len(graph)
        uf = UnionFind(n)
        for i in range(n):
            for j in graph[i]:
                if uf.is_connected(i, j):
                    return False
                uf.union(graph[i][0], j)
        return True


def main():
    sol = Solution()
    res = sol.isBipartite([[1,3],[0,2],[1,3],[0,2]])
    print(res)

main()