class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int total_width = 0;
        int s_len = s.length();
        vector<int> ans(2, 0);
        ans[0] = 1;
        for (int i = 0; i < s_len; i += 1) {
            if (ans[1] + widths[ s[i] - 'a' ] <= 100) {
                ans[1] += widths[ s[i] - 'a' ];
            }
            else {
                ans[0] += 1;
                ans[1] = 0;
                // 该项推倒重来
                i -= 1;
            }
        }
        return ans;
    }
};
