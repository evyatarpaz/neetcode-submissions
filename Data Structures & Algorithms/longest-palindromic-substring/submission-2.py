class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        if not s: return ""

        n = len(s)

        if n == 1: return s[0]

        def helper_expend(left : int, right : int) -> tuple:

            while left >= 0 and right < n and s[left] == s[right]:

                left -= 1
                right += 1
            
            pal_len = right - left - 1

            return (left+1,right,pal_len)
        
        max_pal = (0,0,0) #(start,end,len) 

        for i in range(n):

            pal1 = helper_expend(i,i) # there is a mid and stat at i

            pal2 = helper_expend(i,i+1) # there isn't a mid 

            max_pal = max(pal1, pal2, max_pal, key=lambda x: x[2]) # take the loger pal

        start,end,_ = max_pal

        return s[start:end]

