class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        up = 0
        down = len(matrix) - 1
        while up <= down:
            mid = (up + down) // 2
            if matrix[mid][0] > target:
                down = mid - 1
            elif matrix[mid][-1] < target:
                up = mid + 1
            else:
                break
        if not (up <= down):
            return False

        row = (up + down) // 2
        left = 0
        right = len(matrix[row]) - 1
        mid = (left + right) // 2
        while left <= right:
            if matrix[row][mid] > target:
                right = mid - 1
                mid = (left + right) // 2
            elif matrix[row][mid] < target:
                left = mid + 1
                mid = (left + right) // 2
            else:
                return True
        return False

            