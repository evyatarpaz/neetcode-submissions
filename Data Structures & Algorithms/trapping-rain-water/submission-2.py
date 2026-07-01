class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        prefix = [0] * n
        postfix = [0] * n

        prefix[0] = height[0]
        postfix[n-1] = height[n-1]
        for i in range(1,n):
            prefix[i] = max(prefix[i-1],height[i])
            j = n - 1 - i
            postfix[j] = max(postfix[j + 1], height[j])
        cur_sum = 0
        for i in range(0,n):
            cur_sum += min(prefix[i], postfix[i]) - height[i]
        return cur_sum