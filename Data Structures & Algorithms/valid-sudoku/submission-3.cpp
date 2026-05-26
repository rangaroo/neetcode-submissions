class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for (int row = 0; row < n; ++row) {
            unordered_set<char> s;
            for (int j = 0; j < n; ++j) {
                if (board[row][j] == '.') continue;
                if (s.count(board[row][j])) return false;
    
                s.insert(board[row][j]);
            }
        }
    
        for (int column = 0; column < n; ++column) {
            unordered_set<char> s;
            for (int i = 0; i < n; ++i) {
                if (board[i][column] == '.') continue;
                if (s.count(board[i][column])) return false;
    
                s.insert(board[i][column]);
            }
        }
    
        for (int square = 0; square < n; square++) {
            unordered_set<char> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
    
                    if (board[row][col] == '.') continue;
                    if (s.count(board[row][col])) return false;
    
                    s.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
