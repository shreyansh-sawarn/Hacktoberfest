class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prev = 0
        ans = -2147483647
        for i in nums:
            tempi = prev+i
            if tempi > 0:
                prev = tempi
            else:
                prev = 0
            if tempi > ans:
                ans = tempi
        return ans