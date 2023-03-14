from typing import *


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        # solve equation
        # for [i][j] take min(rowSum[i], colSum[j])
        m, n = len(rowSum), len(colSum)
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                res[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= res[i][j]
                colSum[j] -= res[i][j]
        return res


def main():
    sol = Solution()
    rowSum = [5,7,10]
    colSum = [8,6,8]
    res = sol.restoreMatrix(rowSum, colSum)
    print(res)

main()