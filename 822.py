from typing import *

class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        # there is a set of cards with both sides of integer
        # we can flip any card to the other side
        # pick card whose back is different from front of all cards
        # find the smallest such number and return it
        # if no such number, return 0
        # end   
        
        # idea: only have to cards sharing same number of both sides
        # if a card is not such, it can be flipped to the other side
        # if a card is such, it can't be flipped to the other side
        # so we can find the smallest number that is not such
        
        # 1. find all cards sharing same number of both sides
        # 2. find the smallest number that is not such
        # 3. return it

        diff_side = set()
        same_side = set()
        for i in range(len(fronts)):
            if fronts[i] == backs[i]:
                same_side.add(fronts[i])
            else:
                diff_side.add(fronts[i])
                diff_side.add(backs[i])

        res = float('inf')  
        for num in diff_side:
            if num not in same_side:
                res = min(res, num)
        return res if res != float('inf') else 0




def main():
    sol = Solution()
    res = sol.flipgame()
    print(res)

main()