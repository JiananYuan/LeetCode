class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        string tmp = a;
        int cnt = 1;
        bool found = false;
        while (tmp.length() < 2 * lena + lenb) {
            if (tmp.find(b) != -1) {
                found = true;
                break;
            }
            tmp += a;
            cnt += 1;
        }
        return found ? cnt : -1;
    }
};
