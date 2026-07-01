class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # dictionary
        # d = dict()
        # for i in nums:
        #     if i in d:
        #         return True
        #     else:
        #         d[i] = 1
        # return False
        ## comper the len of the set of nums against the len of nums
        return (len(set(nums)) < len(nums))