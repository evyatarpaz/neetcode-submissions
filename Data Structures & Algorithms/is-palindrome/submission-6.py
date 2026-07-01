class Solution:
    def isPalindrome(self, s: str) -> bool:
        # s = ''.join([char for char in s if char.isalnum()])
        # s = s.lower()
        # if s == s[::-1]:
        #     return True
        # return False

        i,j = 0 ,(len(s)-1)
        while i < j:
            if not self.isAlNum(s[i]):
                i+=1
                continue 
            if not self.isAlNum(s[j]):
                j-=1
                continue
            if s[i].lower() != s[j].lower():
                return False
            i+=1
            j-=1
        return True
    def isAlNum(self, c):
        return (ord('A') <= ord(c) <= ord('Z') or
                ord('a') <= ord(c) <= ord('z') or
                ord('0') <= ord(c) <= ord('9')) 