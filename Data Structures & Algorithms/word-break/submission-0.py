class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s: return True

        if not wordDict: return False

        word_set = set(wordDict) # for O(1) lookup

        n = len(s) + 1

        dp = [False] * (n)
        dp[0] = True

        for i in range(1,n):
            for j in range(0,i):
                if dp[j] == True and s[j:i] in word_set:
                    dp[i] = True
                    break
        
        return dp[-1]