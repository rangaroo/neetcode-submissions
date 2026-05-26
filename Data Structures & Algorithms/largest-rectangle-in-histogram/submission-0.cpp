class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);

        stack<pair<int, int>> s;
        
        // for right corners
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[i] < s.top().first) {
                right[s.top().second] = i;
                s.pop();
            }

            s.push({heights[i], i});
        } 

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[i] < s.top().first) {
                left[s.top().second] = i;
                s.pop();
            }

            s.push({heights[i], i});
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};
