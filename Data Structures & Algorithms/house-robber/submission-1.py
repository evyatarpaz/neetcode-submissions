class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        if len(nums) == 2:
            return max(nums[0],nums[1])

        if len(nums) == 3:
            return max(nums[-1] + nums[-3], nums[-2])

        dp = [0] * (len(nums))
        dp[len(nums) - 1] = nums[-1]
        dp[len(nums) - 2] = nums[-2]
        dp[len(nums) - 3] = nums[-1] + nums[-3]

        for i in range(len(nums)-4,-1,-1):
            dp[i] = max(dp[i+2],dp[i+3]) + nums[i]

        return max(dp[0],dp[1])