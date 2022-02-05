class Solution {
public:
    int dir[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int n, m;
    bool visited[20][20] = { false };

    bool check(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] && !visited[x][y];
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        int maxx = grid[x][y];
        // cout << x << " " << y << ": " << endl;
        for (int i = 0; i < 4; i += 1) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (check(grid, tx, ty)) {
                // cout << tx << " " << ty << endl;
                visited[tx][ty] = true;
                maxx = max(maxx, grid[x][y] + dfs(grid, tx, ty));
            }
        }
        // cout << "====" << maxx << "====" << endl;
        return maxx;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxx = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j]) {
                    memset(visited, 0, sizeof(visited));
                    visited[i][j] = true;
                    maxx = max(maxx, dfs(grid, i, j));
                }
            }
        }
        return maxx;
    }
};
