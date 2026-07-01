class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i, num in enumerate(nums):
            d[num] = i
        for i, num in enumerate(nums):
            dif = target - num
            if dif in d and d[dif] != i:
                return [i,d[dif]]
        return []