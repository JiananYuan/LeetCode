class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i += 3) {
            for (int j = 0; j < col; j += 3) {
                if (!check_block(board, i, j)) {
                    return false;
                }
            }
        }

        for (int i = 0; i < row; i += 1) {
            if (!check_row(board, i)) {
                return false;
            }
        }

        for (int i = 0; i < col; i += 1) {
            if (!check_col(board, i)) {
                return false;
            }
        }

        return true;
    }

    inline bool check_block(vector<vector<char>>& board, int start_x, int start_y) {
        bool mark[10] = { false };
        for (int i = start_x; i < start_x + 3; i += 1 ) {
            for (int j = start_y; j < start_y + 3; j += 1) {
                if (board[i][j] == '.')  continue;
                if (mark[ board[i][j] - '0' ] == false) {
                    mark[ board[i][j] - '0' ] = true;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }

    inline bool check_row(vector<vector<char>>& board, int row) {
        bool mark[10] = { false };
        for (int i = 0; i < 9; i += 1 ) {
            if (board[row][i] == '.')  continue;
            if (mark[ board[row][i] - '0' ] == false) {
                mark[ board[row][i] - '0' ] = true;
            } 
            else {
                return false;
            }
        }
        return true;
    }

    inline bool check_col(vector<vector<char>>& board, int col) {
        bool mark[10] = { false };
        for (int i = 0; i < 9; i += 1 ) {
            if (board[i][col] == '.')  continue;
            if (mark[ board[i][col] - '0' ] == false) {
                mark[ board[i][col] - '0' ] = true;
            } 
            else {
                return false;
            }
        }
        return true;
    }

};
