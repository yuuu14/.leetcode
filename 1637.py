from typing import *


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        # directly, first sort and then check max diff
        def sort(xs):
            return max(xs[i]-xs[i-1] for i in range(1, len(xs)))
        
        def bucket(xs):
            # x_max - x_min <= max_gap * (n-1)
            x_min, x_max, n = min(xs), max(xs), len(xs)
            bucket_size = max(1, (x_max-x_min) // (n-1))
            bucket_num = (x_max - x_min) // bucket_size + 1
            buckets = [[1e9, 0] for _ in range(bucket_num)]
            for x in xs:
                b = (x - x_min) // bucket_size
                buckets[b][0] = min(buckets[b][0], x)
                buckets[b][1] = max(buckets[b][1], x)
            cur_max = 1e9
            res = 0
            print(buckets)
            for b_min, b_max in buckets:
                if b_min > b_max:
                    continue
                res = max(res, b_min - cur_max)
                cur_max = b_max
            return res


        xs = sorted(x for x, _ in points)
        # return sort(xs)
        return bucket(xs)


def main():
    sol = Solution()
    # points = [[8,7],[9,9],[7,4],[9,7]]
    points = [[1,5],[1,70],[3,1000],[55,700],[999876789,53],[987853567,12]]
    res = sol.maxWidthOfVerticalArea(points)
    print(res)

main()