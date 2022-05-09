class Solution {
public:
    void solve(vector<int>& vec, int& st, int& en, string& s, int s_pos) {
        if (s_pos == s.length()) {
            return;
        }
        if (s[s_pos] == 'I') {
            vec.push_back(st);
            st += 1;
            solve(vec, st, en, s, s_pos + 1);
        }
        else {
            vec.push_back(en);
            en -= 1;
            solve(vec, st, en, s, s_pos + 1);
        }
    }

    vector<int> diStringMatch(string s) {
        int len = s.length();
        int st = 0, en = len;
        vector<int> vec;
        solve(vec, st, en, s, 0);
        vec.push_back(st);
        return vec;
    }
};
