class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <int, vector<char>> rows;
        unordered_map <int, vector<char>> cols;
        map <pair<int, int>, vector<char>> boxes;
        
        int n = board.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char curr = board[i][j];
                if (curr != '.') {
                    rows[i].push_back(curr);
                    cols[j].push_back(curr);
                    boxes[{i/3, j/3}].push_back(curr);
                }
            }
        }

        unordered_set <char> unique;

        for (auto row : rows) {
            unique.insert(row.second.begin(), row.second.end());
            if (unique.size() != row.second.size()) {
                return false;
            }
            unique.clear();
        }

        for (auto col : cols) {
            unique.insert(col.second.begin(), col.second.end());
            if (unique.size() != col.second.size()) {
                return false;
            }
            unique.clear();
        }

        for (auto box : boxes) {
            unique.insert(box.second.begin(), box.second.end());
            if (unique.size() != box.second.size()) {
                return false;
            }
            unique.clear();
        }
        return true;
    }
};
