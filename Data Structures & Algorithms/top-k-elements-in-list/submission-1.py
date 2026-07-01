class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # d = dict()
        # for num in nums:
        #     if num in d:
        #         d[num] += 1
        #     else:
        #         d[num] = 1
        # res = []
        # for i in range(k):
        #     m = max(d,key=d.get)
        #     res.append(m)
        #     d.pop(m)
        # return res

        count  = defaultdict(int)
        for num in nums:
            count[num] += 1
        freq = [[] for i in range(len(nums) + 1)]
        for num, cou in count.items():
            freq[cou].append(num)
        res = []
        for i in range(len(freq) -1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res
        