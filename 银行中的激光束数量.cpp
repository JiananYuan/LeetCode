class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = int(bank.size());
        int n = int(bank[0].size());
        int i = 0, j = 0;
        long long cnt = 0;
        for (i = 0; i < m; i += 1) {
            for (j = 0; j < n; j += 1) {
                if (bank[i][j] == '1') {
                    cnt += 1;
                }
            }
            if (cnt) {
                i += 1;
                break;
            }
        }
        long long ans = 0;
        long long last_cnt = cnt;
        for (; i < m; i += 1) {
            cnt = 0;
            for (j = 0; j < n; j += 1) {
                if (bank[i][j] == '1') {
                    cnt += 1;
                }
            }
            if (cnt) {
                ans = ans + last_cnt * cnt;
                last_cnt = cnt;
            }
        }
        return ans;
    }
};
