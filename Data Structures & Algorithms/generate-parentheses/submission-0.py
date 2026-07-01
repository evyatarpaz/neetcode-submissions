class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []

        def backtr(openN,closeN):
            if openN == closeN == n:
                res.append("".join(stack))
                return

            if openN < n:
                stack.append('(')
                backtr(openN+1,closeN)
                stack.pop()

            if closeN < openN:
                stack.append(')')
                backtr(openN,closeN+1)
                stack.pop()
        backtr(0,0)
        return res
