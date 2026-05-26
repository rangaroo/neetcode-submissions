class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                int x = stoi(tokens[i]);
                s.push(x);
            } else {
                int a = s.top();
                s.pop();

                int b = s.top();
                s.pop();

                if (tokens[i] == "+") {
                    s.push(b + a);
                } else if (tokens[i] == "-") {
                    s.push(b - a);
                } else if (tokens[i] == "*") {
                    s.push(b * a);
                } else if (tokens[i] == "/") {
                    s.push(b / a);
                }
            }
        }

        return s.top();
    }
};
