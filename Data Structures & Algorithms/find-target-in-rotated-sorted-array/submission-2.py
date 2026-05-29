class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def find_rotations_idx(arr):
            left, right = 0, len(arr) - 1
            boundary_index = -1

            while left <= right:
                mid = (left + right) // 2

                if arr[mid] <= arr[boundary_index]:
                    boundary_index = mid
                    right = mid - 1
                else:
                    left = mid + 1
            
            return boundary_index
        
        rotation_idx = find_rotations_idx(nums)

        def find(arr, target):
            left, right = 0, len(arr) - 1

            while left <= right:
                mid = (left + right) // 2

                if arr[mid] == target:
                    return mid
                elif arr[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            
            return -1
        
        left_partition = find(nums[:rotation_idx], target)
        right_partition = find(nums[rotation_idx:], target)

        if right_partition != -1:
            return right_partition + rotation_idx

        return left_partition