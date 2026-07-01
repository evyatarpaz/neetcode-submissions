from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        f_s1 = Counter(s1)
        f_s2 = {}
        left, right = 0,0
        ns1 = len(s1)
        ns2 = len(s2)

        if ns2 < ns1:
            return False
        
        while right < ns2:

            f_s2[s2[right]] = f_s2.get(s2[right],0) + 1

            if right - left + 1 > ns1:
                f_s2[s2[left]] -= 1
                if f_s2[s2[left]] == 0:
                    f_s2.pop(s2[left])
                left+=1

            if (right - left + 1) == ns1:
                if f_s2 == f_s1:
                    return True
                    
            right+=1

        return False



