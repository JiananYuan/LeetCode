class Solution {
public:
    bool checkString(string s) {
        int len = s.length();
        int pos = 0;
        while (pos < len && s[pos] == 'a') {
            pos += 1;
        }
        while (pos < len && s[pos] == 'b') {
            pos += 1;
        }
        return pos == len;
    }
};
