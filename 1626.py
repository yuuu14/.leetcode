from typing import *

class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        score_age_list = list(zip(scores, ages))
        score_age_list.sort(key=lambda x:(-x[0], -x[1]))
        max_score_list = [0] * len(ages)
        for i, (s, a) in enumerate(score_age_list):
            for j in range(i):
                if score_age_list[j][1] >= a:
                    max_score_list[i] = max(max_score_list[i], max_score_list[j])
            max_score_list[i] += s
        return max(max_score_list)     


def main():
    sol = Solution()
    scores = [10,9,8,7,6]
    ages = [2,1,5,4,3]
    res = sol.bestTeamScore(scores, ages)
    print(res)

main()