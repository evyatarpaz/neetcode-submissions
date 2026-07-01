class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        
        if not coins:
            return -1
        
        dp = [float('inf')] * (amount+1)
        dp[0] = 0
        for coin in coins:
            for i in range(coin,amount+1):
                if dp[i - coin] != float('inf'):
                    dp[i] = min(dp[i],dp[i - coin] +1)

        return dp[-1] if dp[-1] != float('inf') else -1