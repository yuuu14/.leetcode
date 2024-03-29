# in a int list, check whether there exists subset whose gcd==
# clearly a set A, if its subset B's gcd==1, then gcd(A)==1 as well

#from functools import reduce
from math import gcd

class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return gcd(*nums) == 1