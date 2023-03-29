from typing import *
from math import comb

    
class Solution:
    def countVowelStrings(self, n: int) -> int:
        # instead of filling n positions with 5 choices
        #  considering to grouping n positions into 5 partitions with ordering
        res = comb(n+4, 4)
        return res


def main():
    sol = Solution()
    res = sol.countVowelStrings(n=2)
    print(res)

main()