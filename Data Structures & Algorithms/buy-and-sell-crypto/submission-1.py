class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        j = 0
        max = 0
        sell = 0
        while j < len(prices) and i < len(prices):
            if prices[j] - prices[i] < 0:
                i+=1
            else:
                sell = prices[j] - prices[i]
                if sell > max:
                    max = sell
                j+=1
        return max
