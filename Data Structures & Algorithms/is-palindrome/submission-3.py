class Solution:
    def isPalindrome(self, s: str) -> bool:
        # s = ''.join([char for char in s if char.isalnum()])
        # s = s.lower()
        # if s == s[::-1]:
        #     return True
        # return False

        i,j = 0 ,(len(s)-1)
        s = s.lower()
        while i < j:
            if not s[i].isalnum():
                i+=1
                continue 
            if not s[j].isalnum():
                j-=1
                continue
            if s[i] != s[j]:
                return False
            i+=1
            j-=1
        return True
                