class Solution {
private:
    const static int N = 35;
    string s[N];

public:
    Solution() {
        s[1] = "1";
    }

    string countAndSay(int n) {
        for (int i = 2; i <= n; i += 1) {
            int len = s[i-1].length();
            for (int j = 0; j < len; ) {
                int cnt = 0;
                char ch = s[i-1][j];
                while (s[i-1][j] == ch) {
                    cnt += 1;
                    j += 1;
                }
                s[i] += to_string(cnt);
                s[i] += ch;
            }
        }
        return s[n];
    }
};
