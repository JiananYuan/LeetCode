class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; i -= 1) {
            for (int j = i + 1; j <= n; j += 1) {
                int tmp = 0x7fffffff;
                for (int k = i; k < j; k += 1) {
                    tmp = min(tmp, k + max(dp[i][k-1], dp[k+1][j]));
                }
                dp[i][j] = tmp;
            }
        }
        return dp[1][n];
    }
};
