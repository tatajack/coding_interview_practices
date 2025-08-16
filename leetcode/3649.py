class Solution:
    def perfectPairs(self, nums: List[int]) -> int:
        nums = sorted([abs(x) for x in nums])
        i, ans = 0, 0
        for j in range(len(nums)):
            while i < j and nums[i] < nums[j] / 2.0:
                i += 1
            ans += j - i
        return ans


# a >= b >= a/2
