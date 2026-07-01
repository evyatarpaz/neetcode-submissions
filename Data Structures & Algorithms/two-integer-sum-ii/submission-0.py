class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i ,j = 0 , len(numbers) - 1
        while i < j:
            numsum = numbers[i] + numbers[j]
            if numsum == target:
                return [i+1,j+1]
            if numsum > target:
                j-=1
            if numsum < target:
                i+=1
        return -1