class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        array = []
        for i in range(len(position)):
            array.append((position[i],speed[i]))
        array.sort(reverse=True)
        stack = []
        for tup in array:
            time = (target - tup[0]) / tup[1]
            if not stack:
                stack.append(time)
                continue
            top = stack[-1]
            if top >= time:
                continue
            else:
                stack.append(time)
        
        return len(stack)