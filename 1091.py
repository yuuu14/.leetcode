from typing import *

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # bfs
        if grid[0][0] == 1:
            return -1
        n = len(grid)
        if n == 1:
            return 1
        q = [(0, 0)]
        grid[0][0] = 1
        step = 1
        while q:
            step += 1
            tmp = []
            for x, y in q:
                for i, j in [(0, 1), (1, 0), (1, 1), (-1, 0), (0, -1), (-1, -1), (1, -1), (-1, 1)]:
                    if 0 <= x + i < n and 0 <= y + j < n and grid[x + i][y + j] == 0:
                        if x + i == n - 1 and y + j == n - 1:
                            return step
                        tmp.append((x + i, y + j))
                        grid[x + i][y + j] = 1
            q = tmp
        return -1
    

def main():
    sol = Solution()
    res = sol.shortestPathBinaryMatrix([[0,0,0],[1,1,0],[1,1,0]])
    print(res)

main()