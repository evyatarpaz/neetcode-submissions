class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = {}
        res = 0

        for num in nums:
            if num not in mp.keys():
                mp[num] = mp.get(num-1,0) + mp.get(num+1,0) + 1
                mp[num - mp.get(num-1,0)] = mp[num]
                mp[num + mp.get(num + 1,0)] = mp[num]
                res = max(res,mp[num])
        return res
        # numSet = set(nums)
        # maxlen = 0

        # for num in numSet:
        #     if (num - 1) not in numSet:
        #         length = 1
        #         while (num + length) in numSet:
        #             length +=1
        #         maxlen = max(maxlen,length)
        # return maxlen

        ###########################################
        # we can solve it very easily by sorting the array
        # if not nums:
        #     return 0
        # res = 0
        # nums.sort()
        
        # curr, streak = nums[0], 0
        # i = 0
        # while i < len(nums):
        #     if curr != nums[i]:
        #         curr = nums[i]
        #         streak = 0
        #     while i < len(nums) and nums[i] == curr:
        #         i += 1
        #     streak += 1
        #     curr += 1
        #     res = max(res, streak)
        # return res

