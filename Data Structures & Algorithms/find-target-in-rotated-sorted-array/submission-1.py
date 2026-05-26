class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def find_rotation_idx(nums):
            left, right = 0, len(nums) - 1
            boundary_index = -1

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] <= nums[-1]:
                    boundary_index = mid
                    right = mid - 1
                else:
                    left = mid + 1
            
            return boundary_index

        rotation_idx = find_rotation_idx(nums)

        def find(nums):
            left, right = 0, len(nums) - 1

            while left <= right:
                mid = (left + right) // 2

                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            
            return -1

        left_side = find(nums[:rotation_idx])
        right_side = find(nums[rotation_idx:])

        if right_side != -1:
            return right_side + rotation_idx
        else:
            return left_side