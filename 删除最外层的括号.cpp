class Solution {
public:
    string removeOuterParentheses(string s) {
        int i = 0;
        stack<char> stk;
        int s_len = s.length();
        int start = 0;
        string ans = "";
        for (i = 0; i < s_len; i += 1) {
            char ch = s[i];
            if (stk.empty()) {
                start = i;
                stk.push(ch);
            }
            else {
                if (ch == '(') {
                    stk.push(ch);
                }
                else {  // ')' 
                    stk.pop();
                    if (stk.empty()) {
                        ans += s.substr(start + 1, i - start - 1);
                    }
                }
            }
        }
        return ans;
    }
};
