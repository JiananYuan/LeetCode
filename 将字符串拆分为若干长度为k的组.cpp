class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int len = s.length();
        int i = 0;
        string tmp = "";
        while (i < len) {
            tmp = "";
            for (int j = 0; j < k && i < len; j += 1, i += 1) {
                tmp += s[i];
            }
            if (tmp.length() == k) {
                ans.emplace_back(tmp);
            }
        }
        if (tmp.length() != k) {
            while (k - tmp.length() > 0) {
                tmp += fill;
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
