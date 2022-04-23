class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        for (int i = 0; i < m; i += 1) {
            int minx = matrix[i][0], minid = 0;
            for (int j = 1; j < n; j += 1) {
                if (matrix[i][j] < minx) {
                    minx = matrix[i][j];
                    minid = j;
                }
            }
            bool need = true;
            for (int j = 0; j < m; j += 1) {
                if (minx < matrix[j][minid]) {
                    need = false;
                    break;
                }
            }
            if (need) {
                res.push_back(minx);
            }
        }
        return res;
    }
};

