class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0

        n = len(nums)

        if n == 1: return nums[0]

        global_max = 0
        curr_max = 0
        curr_min = 0

        for num in nums:
            max_dot = curr_max * num
            min_dot = curr_min * num

            curr_max = max(num,max_dot,min_dot)
            curr_min = min(num,max_dot,min_dot)

            global_max = max(global_max,curr_max,curr_min)

            

        return global_max