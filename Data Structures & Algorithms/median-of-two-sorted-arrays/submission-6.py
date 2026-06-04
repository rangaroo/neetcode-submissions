class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total = len(nums1) + len(nums2)
        half = total // 2

        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A

        left, right = 0, len(A) - 1
        while True:
            i = (left + right) // 2
            j = half - i - 2 # to take the index

            A_left = A[i] if i >= 0 else float("-inf")
            A_right = A[i + 1] if i + 1 < len(A) else float("inf")
            B_left = B[j] if j >= 0 else float("-inf")
            B_right = B[j + 1] if j + 1 < len(B) else float("inf")

            if A_left <= B_right and B_left <= A_right:
                if total % 2:
                    # odd case
                    return min(A_right, B_right)          
                
                # even case
                return ( max(A_left, B_left) + min(A_right, B_right) ) / 2

            elif A_left > B_right:
                right = i - 1
            else:
                left = i + 1
