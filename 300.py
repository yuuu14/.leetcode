from typing import *


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        def binary_search(nums, end, target):
            left, right = 0, min(end, len(nums))
            result = -1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] >= target:
                    result = mid
                    right = mid - 1
                else:
                    left = mid + 1
            cur = 0
            if result == -1: # all smaller than target
                end += 1
                cur = end
            else:
                cur = result
            nums[cur] = target
            return end

        stack = [0] * len(nums)
        end = -1
        res = 0
        for num in nums:
            end = binary_search(stack, end, num)
            res = max(res, end)
        return res+1


def main():
    sol = Solution()
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    res = sol.lengthOfLIS(nums)
    print(res)


main()
