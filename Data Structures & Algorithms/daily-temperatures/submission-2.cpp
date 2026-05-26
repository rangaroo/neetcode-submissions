class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<pair<int, int>> s;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!s.empty() && temperatures[i] >= s.top().first) {
                s.pop();
            }

            if (s.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = s.top().second - i;
            }

            //cout << "(" << temperatures[i] << "," << i << ") ";
            s.push({temperatures[i], i});
        }

        return ans;
    }
};
