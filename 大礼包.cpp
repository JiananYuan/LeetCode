class Solution {
public:
    map<vector<int>, int> mp;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (mp.count(needs) == 1) {
            return mp[needs];
        }
        int ans = 0;
        int needs_len = int(needs.size());
        for (int i = 0; i < needs_len; i += 1) {
            ans += needs[i] * price[i];
        }
        int special_len = int(special.size());
        for (int i = 0; i < special_len; i += 1) {
            vector<int> next = needs;
            bool isOverflow = false;
            for (int j = 0; j < needs_len; j += 1) {
                if (next[j] < special[i][j]) {
                    isOverflow = true;
                    break;
                }
            }
            if (!isOverflow) {
                for (int j = 0; j < needs_len; j += 1) {
                    next[j] -= special[i][j];
                }
                ans = min(ans, dfs(price, special, next) + special[i].back());
            }
        }
        return mp[needs] = ans;
    }
};
