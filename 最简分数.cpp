class Solution {
public:
    inline int gcd(int a, int b) {  // a < b
        int r = b % a;
        while (r != 0) {
            b = a;
            a = r;
            r = b % a;
        }
        return a;
    }

    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; i += 1) {
            for (int j = 1; j < i; j += 1) {
                if (gcd(j, i) == 1) {
                    string tmp = to_string(j) + "/" + to_string(i);
                    ans.emplace_back(tmp);
                }
            }
        }
        return ans;
    }
};
