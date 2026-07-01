class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper_rob(start : int, end : int) -> int:
            if not nums:
                return 0
            
            rob_minus_2 = 0
            rob_minus_1 = 0
            
            for i in range(start,end):
                current_max = max(rob_minus_1, rob_minus_2 + nums[i])
                
                rob_minus_2 = rob_minus_1
                rob_minus_1 = current_max
                
            return rob_minus_1

        n = len(nums)

        if n == 1:
            return nums[0]

        return max(helper_rob(0,n-1),helper_rob(1,n))
                