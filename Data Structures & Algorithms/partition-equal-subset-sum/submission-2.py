class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        if not nums: return True

        n = len(nums)

        if n == 1: return False

        nums_sum = sum(nums)
        
        if nums_sum % 2 == 1: return False
        
        target = nums_sum // 2

        dp = [False] * (target + 1)
        dp[0] = True

        for num in nums:
            for i in range(target,num-1,-1):
                dp[i] = dp[i] or dp[i-num]

        return dp[-1]
