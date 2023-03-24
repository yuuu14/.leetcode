from typing import *


class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        # up down up down ... up down up
        # part 1 increasing ... part 2 middle ... part 3 increasing
        n = len(arr)
        if n == 1:
            return 0
        i, j = 0, n-1
        while i < n-1 and arr[i] <= arr[i+1]:
            i += 1
        if i == n-1:
            return 0
        while j > 0 and arr[j-1] <= arr[j]:
            j -= 1
        res = j  # keep part 3
        print(i, j)
        p = 0
        while p <= i and j < n:
            # j-p
            if arr[p] <= arr[j]:
                res = min(res, j-p-1)
                p += 1
            else:
                j += 1
        res = min(res, n-i-1)
        return res
        

def main():
    sol = Solution()
    arr = [1,2,3,10,4,2,3,5]
    res = sol.findLengthOfShortestSubarray(arr)
    print(res)

main()