class Solution:
    def climbStairs(self, n: int) -> int:
        """
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2,n+1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[-1]
        """

        perv1 = 1
        perv2 = 1

        for i in range(2,n+1):
            cur = perv1 + perv2
            perv2 = perv1
            perv1 = cur
        
        return perv1


