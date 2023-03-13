from typing import *

class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        engs = max(sum(energy) + 1, initialEnergy) - initialEnergy
        exps = initialExperience
        for e in experience:
            if e >= exps:
                exps = e + 1
            exps += e
        return engs + exps - sum(experience) - initialExperience


def main():
    sol = Solution()
    initialEnergy = 5
    initialExperience = 3
    energy = [1,4,3,2]
    experience = [2,6,3,1]
    res = sol.minNumberOfHours(initialEnergy, initialExperience, energy, experience)
    print(res)

main()