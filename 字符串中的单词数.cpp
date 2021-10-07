class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        stringstream ss(s);
        while (ss >> s) {
            cnt += 1;
            // cout << s << endl;
        }
        return cnt;
    }
};