class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = dict()
        for tav in s:
            if tav in d:
                d[tav] += 1
            else:
                d[tav] = 1
        for tav in t:
            if tav in d:
                d[tav] -=1
            else:
                d[tav] = -1
        for tav in d:
            if d[tav] != 0:
                return False
        return True