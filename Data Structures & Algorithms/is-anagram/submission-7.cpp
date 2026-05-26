class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() < t.size()) {
            return false;
        }

        unordered_map<char, int> m;
        for (char ch : s) {
            m[ch]++;
        }

        for (char ch : t) {
            m[ch]--;
        }

        for (auto [ch, count] : m) {
            if (count > 0) {
                return false;
            }
        }

        return true;
    }
};
