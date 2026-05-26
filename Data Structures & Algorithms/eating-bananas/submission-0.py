class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def feasible(k, piles, h):
            sum_hours = 0

            for pile in piles:
                sum_hours += math.ceil(pile / k)

            return sum_hours <= h

        left, right = 1, 1e13
        boundary_index = -1

        while left <= right:
            mid = (left + right) // 2

            if feasible(mid, piles, h):
                boundary_index = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return int(boundary_index)