class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        return res
        ##########################################
        # n = len (nums)
        # res = [0] * n
        # pref = [0] * n
        # suff = [0] * n
        # pref[0] = suff[n-1] = 1
        # for i in range(1,n):
        #     pref[i] = nums[i-1] * pref[i-1]
        #     suff[n-i-1] = nums[n-i] * suff[n-i]
        # for i in range(0,n):
        #     res[i] = pref[i] * suff[i]
        # return res
        ############################################
        # res = [0] * len(nums)
        # mul = 1
        # zero_count = 0
        # for num in nums:
        #     if num:
        #         mul *= num
        #     else:
        #         zero_count +=1
        # if zero_count > 1:
        #     return [0]* len(nums)
        # for i,num in enumerate(nums):
        #     if zero_count > 0:
        #         if num == 0:
        #             res[i] = mul
        #         else:
        #             res[i] = 0
        #     else:
        #         res[i] = mul // num
        # return res
        
