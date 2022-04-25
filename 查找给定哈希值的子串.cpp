class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        map<char, int> mp;
        for (int i = 1; i <= 26; i += 1) {
            mp['a' - 1 + i] = i;
        }
        long long p = 1, h = 0;
        int len = s.length();
        for (int i = len - k; i < len; i += 1) {
            h = (h + mp[s[i]] * p) % modulo;
            p = (p * power) % modulo;
        }
        int pos = 0;
        if (h == hashValue) {
            pos = len - k;
        }
        for (int i = len - k - 1; i >= 0; i -= 1) {
            h = ((h * power - p * mp[s[i + k]]) % modulo + modulo + mp[s[i]]) % modulo;
            if (h == hashValue) {
                pos = i;
            }
        }
        return s.substr(pos, k);
    }
};

