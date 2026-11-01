class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};  // O(n) space
        int cols[9] = {0};  // 000000000
        int boxes[9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    // 000001000 (1 on 3rd pos) == 4
                    int bit_pos = board[i][j] - '1';  
                    // Shift binary representation of 1 to left by bit_pos
                    int mask = 1 << bit_pos;  // Bitmask

                    int box = (i / 3) * 3 + (j / 3);

                    // If seen, using bitwise AND
                    if ((rows[i] & mask)
                    || (cols[j] & mask) 
                    || (boxes[box] & mask)) {
                        return false;
                    }
                    
                // If not seen, then insert using bitwise OR
                rows[i] = rows[i] | mask;
                cols[j] = cols[j] | mask;
                boxes[box] = boxes[box] | mask;
                }
            }
        }
        return true;
    }
};
