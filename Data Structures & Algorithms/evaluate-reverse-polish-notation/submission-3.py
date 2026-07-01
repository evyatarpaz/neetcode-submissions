class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for c in tokens:
            if c == '+':
                stack.append(stack.pop() + stack.pop())
                continue 
            if c == '-':
                a = stack.pop()
                b = stack.pop()
                stack.append(b - a)
                continue
            if c == '*':
                stack.append(stack.pop() * stack.pop())
                continue
            if c == '/':
                a = stack.pop()
                b = stack.pop()
                stack.append(int(float(b) / a))
                continue
            stack.append(int(c))
        return stack[0]

