class Solution {
public:
    string longestNiceSubstring(string s) {
        int len = s.length();
        // i  长度
        for (int i = len; i >= 2; i -= 1) {
            // j 起点
            for (int j = 0; j <= len - i; j += 1) {
                string subs = s.substr(j, i);
                if (check(subs)) {
                    return subs;
                }
            }
        }
        return "";
    }

    bool check(string& s) {
        int lower = 0;
        int upper = 0;
        for (char ch : s) {
            if (islower(ch)) {
                lower |= (1 << (ch - 'a'));
            }
            else {
                upper |= (1 << (ch - 'A'));
            }
        }
        bitset<32> l(lower);
        bitset<32> u(upper);
        for (int i = 0; i < 32; i += 1) {
            if (l[i] != u[i]) {
                return false;
            }
        }
        return true;
    }
};
