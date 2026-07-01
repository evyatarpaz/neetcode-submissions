class Solution:
    def countSubstrings(self, s: str) -> int:

        if not s: return 0

        n = len(s)

        if n == 1: return 1


        def helper_pal(left : int, right : int) -> int:
            counter = 0
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                counter += 1
            return counter
        
        pal_sum = 0

        for i in range(n):
            pal_sum = pal_sum + helper_pal(i,i) + helper_pal(i,i+1)

        return pal_sum
            

        
