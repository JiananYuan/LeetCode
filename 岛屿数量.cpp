class Solution {
private:
    int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

public:

    int numIslands(vector<vector<char> >& grid) {
        int row = int(grid.size());
        if (row == 0) {
            return 0;
        }
        int col = int(grid[0].size());
        if (col == 0) {
            return 0;
        }
        vector<vector<char> > grid_copy(grid);
        int island_cnt = 0;
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                if (grid_copy[i][j] == '1') {
                    dfs(grid_copy, row, col, i, j);
                    island_cnt += 1;
                    // debug(grid_copy, row, col);
                }
            }
        }
        return island_cnt;
    }

    void dfs(vector<vector<char> >& grid, int& row, int& col, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i += 1) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (check_in_bound(tx, ty, row, col) && grid[tx][ty] == '1') {
                dfs(grid, row, col, tx, ty);
            }
        }
    }

    inline bool check_in_bound(int x, int y, int& row, int& col) {
        return x >= 0 && y >= 0 && x < row && y < col;
    }

    inline void debug(vector<vector<char> >& grid, int& row, int& col) {
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

};
