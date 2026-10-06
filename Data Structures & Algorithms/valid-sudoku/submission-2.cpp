class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set <char> seen; // O(1)

        // For rows
        for (int i = 0; i < n; ++i) {  // O(n^2) time
            for (int j = 0; j < n; ++j) {
                char curr = board[i][j];
                if (seen.count(curr)) {
                    return false;
                }
                if (curr != '.') {  // O(n) space
                    seen.insert(curr);
                }
            }
            seen.clear();
        }

        // For columns
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char curr = board[j][i];
                if (seen.count(curr)) {
                    return false;
                }
                if (curr != '.') {
                    seen.insert(curr);
                }
            }
            seen.clear();
        }

        // For each subboxes
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {  // O(n^2) time
                
                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {

                        char curr = board[row][col];
                        if (seen.count(curr)) {
                            return false;
                        }
                        if (curr != '.') {
                            seen.insert(curr);  // O(n) space
                        }
                    }
                }
                seen.clear();
            }
        }
        return true;
    }
};
