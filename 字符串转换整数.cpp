class Solution {
public:
    int myAtoi(string s) {
        // pointer of string s
        int ptr = 0;
        // discard useeless space
        int len = int(s.length());
        while (ptr < len && s[ptr] == ' ') {
            ptr += 1;
        }
        // judge positive or negative
        bool is_positive = (s[ptr] == '-') ? false : true;
        if (!is_positive || s[ptr] == '+') {
            ptr += 1;
        }
        // skip useless zero
        while (ptr < len && s[ptr] == '0') {
            ptr += 1;
        }
        // calculate
        long ans = 0;
        while (ptr < len) {
            // cout << s[ptr] << " ";
            if (!isdigit(s[ptr])) {
                break;
            }
            int num = s[ptr] - '0';
            ans = ans * 10 + num;
            // overflow judge
            if (is_positive) {
                if (ans > 0x7fffffff) {
                    return 0x7fffffff;
                }
            } 
            else {
                if (ans > 0x80000000) {
                    return 0x80000000;
                }
            }
            ptr += 1;
        }
        return is_positive ? ans : -ans;
    }
};
