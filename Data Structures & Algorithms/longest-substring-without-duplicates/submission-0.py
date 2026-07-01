class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = set()
        i = 0
        j = 0
        res = 0
        while j < len(s):
            while s[j] in chars:
                chars.remove(s[i])
                i+=1
            chars.add(s[j])
            if j-i+1 > res:
                res = j-i+1
            j+=1
        return res
