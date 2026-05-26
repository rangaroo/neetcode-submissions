class Solution {
public:
    bool isValid(string s) {
        stack<char> x;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                x.push(s[i]);
            } else {
                if (x.empty()) {
                    return false;
                }
                else if (s[i] == '}' && x.top() != '{') {
                    return false;
                } else if (s[i] == ']' && x.top() != '[') {
                    return false;
                } else if (s[i] == ')' && x.top() != '(') {
                    return false;
                }
                x.pop();
            }
        }

        return x.empty();
    }
};
