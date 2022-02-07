bool cmp(const pair<char, int>& p1, const pair<char, int>& p2) {
    return p1.second > p2.second;
}

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        pair<char, int> p[3];
        p[0] = {'a', a};
        p[1] = {'b', b};
        p[2] = {'c', c};
        string ans = "";
        while (true) {
            sort(p, p + 3, cmp);
            bool has_next = false;
            for (int i = 0; i < 3; i += 1) {
                auto& pp = p[i];
                if (pp.second <= 0) {
                    break;
                }
                int len = ans.length();
                if (len >= 2 && ans[len - 1] == pp.first && ans[len - 2] == pp.first) {
                    continue;
                }
                pp.second -= 1;
                ans += pp.first;
                has_next = true;
                break;
            }
            if (!has_next) {
                break;
            }
        }
        return ans;
    }

};
