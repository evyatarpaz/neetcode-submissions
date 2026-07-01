class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            leng = len(s)
            res += str(leng)
            res += "#"
            res += s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0

        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            # get the len of each string
            leng = int(s[i:j])
            # add one to j to move past the char "#"
            i = j + 1
            # where the string end
            j = i + leng
            # add it to the Anwar 
            res.append(s[i:j])
            # start of the new word
            i = j
        return res