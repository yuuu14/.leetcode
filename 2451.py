from typing import *
from itertools import pairwise
# from functools import lru_cache


class Solution:
    def oddString(self, words: List[str]) -> str:
        # english alphabet
        n = len(words[0])
        diff = [ord(words[0][i])-ord(words[0][i+1]) for i in range(n-1)]
        count = 1
        k = 0
        for i, word in enumerate(words[1:]):
            for j, (a, b) in enumerate(pairwise(word)):
                if ord(a)-ord(b) != diff[j]:
                    if i and count == 1:
                        return words[0]
                    else:
                        k = i+1  # start with 1
                    break
            else:
                count += 1
                if k:  # count > 1 and k != 0
                    break
        return words[k]




def main():
    sol = Solution()
    res = sol.oddString(words=["aaa","bob","ccc","ddd"])
    print(res)

main()