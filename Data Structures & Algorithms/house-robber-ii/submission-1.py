class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper_rob(nums: List[int]) -> int:
            if not nums:
                return 0
            
            # שני משתנים שמייצגים את dp[i-2] ו- dp[i-1]
            rob_minus_2 = 0
            rob_minus_1 = 0
            
            for num in nums:
                # חישוב הערך הנוכחי על סמך השניים הקודמים
                current_max = max(rob_minus_1, rob_minus_2 + num)
                
                # הזזת ה"חלון" קדימה לקראת הבית הבא
                rob_minus_2 = rob_minus_1
                rob_minus_1 = current_max
                
            return rob_minus_1
        n = len(nums)
        if n == 1:
            return nums[0]
        return max(helper_rob(nums[:n-1]),helper_rob(nums[1:]))
                