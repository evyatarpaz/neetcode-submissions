class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum_sub = 0
        max_sum = nums[0]
        for num in nums:
            # print(sum_sub,max_sum)
            sum_sub += num
            if sum_sub > max_sum:
                max_sum = sum_sub
            
            if sum_sub < 0:
                sum_sub = 0
        
        return max_sum