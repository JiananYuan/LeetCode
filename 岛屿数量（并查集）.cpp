class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = int(grid.size());
        int n = int(grid[0].size());
        vector<int> father(m * n, 0);
        vector<int> ranks(m * n, 0);
        // init
        for (int i = 0; i < m * n; i += 1) {
            father[i] = i;
        }
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (grid[i][j] == '1') {
                    // 上
                    if (i - 1 >= 0) {
                        union_acs(father, ranks, i * n + j, (i - 1) * n + j);
                    }
                    // 下
                    if (i + 1 < m) {
                        union_acs(father, ranks, i * n + j, (i + 1) * n + j);
                    }
                    // 左
                    if (j - 1 >= 0) {
                        union_acs(father, ranks, i * n + j, i * n + j - 1);
                    }
                    // 右
                    if (j + 1 < n) {
                        union_acs(father, ranks, i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        unordered_set<int> us;
        for (int i = 0; i < m * n; i += 1) {
            if (grid[i / n][i % n] == '1') {
                us.insert(find_acs(father, i));
            }
        }
        return int(us.size());
    }

    // 带路径压缩
    int find_acs(vector<int>& father, int x) {
        if (x == father[x]) {
            return x;
        }
        else {
            father[x] = find_acs(father, father[x]);
            return father[x];
        }
    }

    // 按秩合并
    void union_acs(vector<int>& father, vector<int>& ranks, int x, int y) {
        int acs_x = find_acs(father, x);
        int acs_y = find_acs(father, y);
        if (acs_x != acs_y) {
            // int large, small;
            // if (ranks[acs_x] < ranks[acs_y]) {
            //     large = acs_y;
            //     small = acs_x;
            // }
            // else {
            //     large = acs_x;
            //     small = acs_y;
            // }
            // father[small] = large;
            // if (ranks[small] == ranks[large]) {
            //     ranks[large] += 1;
            // }
            father[acs_x] = acs_y;
        }
    }


};
