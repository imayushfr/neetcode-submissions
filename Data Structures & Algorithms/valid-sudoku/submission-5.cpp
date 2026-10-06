class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> boxes;

        int n = board.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char curr = board[i][j];
                if (rows[i].count(curr) 
                || cols[j].count(curr) 
                || boxes[{i/3, j/3}].count(curr)) {
                    return false;
                }

                if (curr != '.') {
                    rows[i].insert(curr);
                    cols[j].insert(curr); 
                    boxes[{i/3, j/3}].insert(curr);
                }
            }
        }
        return true;
    }
};
