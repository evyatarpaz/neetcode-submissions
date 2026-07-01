class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        mul = 1
        zero_count = 0
        for num in nums:
            if num:
                mul *= num
            else:
                zero_count +=1
        if zero_count > 1:
            return [0]* len(nums)
        for i,num in enumerate(nums):
            if zero_count > 0:
                if num == 0:
                    res[i] = mul
                else:
                    res[i] = 0
            else:
                res[i] = mul // num
        return res
