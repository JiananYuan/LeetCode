class Solution {
public:
    const int MOD = 1337;

    int dfs(int a, vector<int>& b, int b_ptr) {
        if (b_ptr < 0) {
            return 1;
        }
        return ((qpow((dfs(a, b, b_ptr - 1) % MOD), 10) % MOD) * (qpow(a, b[b_ptr]) % MOD)) % MOD;
    }

    int qpow(int a, int b) {
        int ans = 1;
        int tmp = a;
        while (b != 0) {
            if (b & 1) {
                ans = ((ans % MOD) * (tmp % MOD)) % MOD;
            }
            tmp = ((tmp % MOD) * (tmp % MOD)) % MOD;
            b >>= 1;
        }
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        return dfs(a, b, int(b.size()) - 1);
    }
};
