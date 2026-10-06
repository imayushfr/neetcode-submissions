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
        for (int sq_no = 0; sq_no < n; ++sq_no) {  // Box number 
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {  // O(n^2) time

                    // (0, 1, 2) (0, 1, 2) Unique pairs
                    int circumferential_row = sq_no / 3;
                    int circumferential_col = sq_no % 3;

                    // (0, 3, 6) (0, 3, 6) Unique pairs
                    int starting_row = circumferential_row * 3;
                    int starting_col = circumferential_col * 3;

                    // Iterating over a subbox
                    int row = starting_row + i;
                    int col = starting_col + j;
                    // cout << row << "," << col << endl;
                    
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
        return true;
    }
};
