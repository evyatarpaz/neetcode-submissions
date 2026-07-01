class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, right = 0,0
        n = len(s)
        max_sub = 0
        max_f = 0
        diff = 0
        dic = {}
        while right < n:
            dic[s[right]] = dic.get(s[right],0) + 1
            max_f = max(dic[s[right]], max_f)
            diff = right - left + 1 - max_f
            if diff <= k:
                print("left: ",left,"right: ",right,"max_sub: ",max_sub,"max_f: ",max_f,"diff: ",diff,"dic: ",dic)
                max_sub = max(max_sub,(right - left +1))
                right +=1
            else:
                dic[s[left]] -= 1
                left +=1
                right +=1
                max_f = max(dic[s[left]], max_f)
            
        return max_sub


        


        return 0
        """ 
        ABBBBBBCCCB
        AABBCC
        left ,right {A:0 , B:2 , C:1} max_sub = 3   max_f = 2, diff = 2
        """