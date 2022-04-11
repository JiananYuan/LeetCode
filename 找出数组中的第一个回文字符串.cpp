class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int len = int(words.size());
        for (int i = 0; i < len; i += 1) {
            if (isHuiwen(words[i])) {
                return words[i];
            }
        }
        return "";
    }
    
    inline bool isHuiwen(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
};

