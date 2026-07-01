class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dict()
        for num in nums:
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
        res = []
        for i in range(k):
            m = max(d,key=d.get)
            res.append(m)
            d.pop(m)
        return res