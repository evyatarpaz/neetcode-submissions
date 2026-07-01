class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        maxsum = 0
        cur_sum = 0
        while left < right:
            height = min(heights[left],heights[right])
            cur_sum = height * (right - left)
            maxsum = max(maxsum,cur_sum)
            if heights[left] < heights[right]:
                left += 1
            elif heights[left] > heights[right]:
                right -= 1
            else:
                left += 1
                right -= 1
        return maxsum