class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        map<map<int, int>, vector<string>> doubleMap;
        for (string str : strs) {
            map<int, int> m;
            for (int j = 0; j < str.size(); ++j) {
                m[str[j] - 'a']++;
            }

            doubleMap[m].push_back(str);
        }

        for (auto [key, val] : doubleMap) {
            res.push_back(val);
        }

        return res;
    }
};
