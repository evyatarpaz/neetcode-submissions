class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        can_reach = 0
        for i in range(len(nums)):
            if i > can_reach: return False

            can_reach = max(i+nums[i], can_reach)

            if can_reach >= target : return True
