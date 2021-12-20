class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int len = int(prices.size());
        prices.push_back(-1);
        long long ans = 0;
        for (int i = 0; i < len; i += 1) {
            long long cnt = 1;
            while (i < len && prices[i] - prices[i + 1] == 1) {
                cnt += 1;
                i += 1;
            }
            ans += (cnt * (cnt + 1)) / 2;
        }
        return ans;
    }
};
