class Solution:
    def isValid(self, s: str) -> bool:
        brackets = []
        n = len(s)
        i = 0
        closeToOpen = { ")" : "(", "]" : "[", "}" : "{" }
        for ch in s:
            if ch in closeToOpen:
                if brackets and brackets[-1] == closeToOpen[ch]:
                    brackets.pop()
                else:
                    return False
            else:
                brackets.append(ch)
        return True if not brackets else False