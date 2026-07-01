class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left = 0
        right = n - 1
        mid = (right + left) // 2
        while left <= right:
            if nums[mid] > target:
                right = mid - 1
                mid = (right + left) // 2
            elif nums[mid] < target:
                left = mid + 1
                mid = (right + left) // 2
            else:
                return mid
        return -1
