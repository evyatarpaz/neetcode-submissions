class TimeMap:

    def __init__(self):
        self.timeMap = {}
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.timeMap:
            self.timeMap[key] = []
        self.timeMap[key].append((value,timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.timeMap:
            return ""

        data = self.timeMap[key]
        left = 0
        right = len(data) - 1
        res = ""
        while left <= right:
            mid = (left + right) // 2
            mid_time = data[mid][1]
            if mid_time <= timestamp:
                res = data[mid][0]
                left = mid + 1
            else:
                right = mid - 1
        return res


