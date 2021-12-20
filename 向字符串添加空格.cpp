class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int len = int(spaces.size());
        int last_index = 0;
        string ans = "";
        int s_len = s.length();
        int u = 0;
        for (int i = 0; i < s_len; i += 1) {
            if (u < len && i == spaces[u]) {
                ans += " ";
                u += 1;
            }
            ans += s[i];
        }
        
        return ans;
    }
};
