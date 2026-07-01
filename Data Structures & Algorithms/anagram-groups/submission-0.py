class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            d = [0]*26
            for tav in s:
                d[ord(tav) - ord('a')] += 1
            res[tuple(d)].append(s)
        return list(res.values())
        