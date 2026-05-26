class TimeMap:

    def __init__(self):
        self.d = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.d:
            self.d[key] = []

        self.d[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.d:
            return ""

        left, right = 0, len(self.d[key]) - 1
        res = -1

        while left <= right:
            mid = (left + right) // 2

            if self.d[key][mid][0] <= timestamp:
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return self.d[key][res][1] if res != -1 else ""
