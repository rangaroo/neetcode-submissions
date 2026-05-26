class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
    
        vector<int> left(n);
        vector<int> right(n);
    
        // fill prefix sums
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
    
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i];
        }
    
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i];
        }
    
        // solve
        for (int i = 1; i < n - 1; ++i) {
            res[i] = left[i - 1] * right[i + 1];
        }
    
        res[0] = right[1];
        res[n - 1] = left[n - 2];
    
        return res;
    }
};
