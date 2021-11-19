class Solution {
public:
    map<long, int> mp;

    int integerReplacement(int n) {
        long ll_n = (long) n;
        dfs(ll_n);
        return mp[ll_n];
    }

    int dfs(long n) {
        if (n == 1) {
            return 0;
        }
        if (mp.count(n)) {
            return mp[n];
        }
        if (n & 1) {
            mp[n] = min(dfs(n - 1), dfs(n + 1)) + 1;
        }
        else {
            mp[n] = dfs(n / 2) + 1;
        }
        return mp[n];
    }
};
