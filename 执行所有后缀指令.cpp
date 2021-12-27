class Solution {
public:
    // 现有一个 n x n 大小的网格
    // startPos = [startrow, startcol]
    // 'L'（向左移动），'R'（向右移动），'U'（向上移动）和 'D'（向下移动）
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int ix = startPos[0];
        int iy = startPos[1];
        int s_len = int(s.size());
        for (int i = 0; i < s_len; i += 1) {
            int cnt = 0;
            int tx = ix, ty = iy;
            for (int j = i; j < s_len; j += 1) {
                if (s[j] == 'L') {
                    if (check(tx, ty - 1, n)) {
                        ty = ty - 1;
                        cnt += 1;
                    }
                    else {
                        break;
                    }
                }
                else if (s[j] == 'R') {
                    if (check(tx, ty + 1, n)) {
                        ty = ty + 1;
                        cnt += 1;
                    }
                    else {
                        break;
                    }
                }
                else if (s[j] == 'U') {
                    if (check(tx - 1, ty, n)) {
                        tx = tx - 1;
                        cnt += 1;
                    }
                    else {
                        break;
                    }
                }
                else if (s[j] == 'D') {
                    if (check(tx + 1, ty, n)) {
                        tx = tx + 1;
                        cnt += 1;
                    }
                    else {
                        break;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    inline bool check(int x, int y, int& n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
  
};
