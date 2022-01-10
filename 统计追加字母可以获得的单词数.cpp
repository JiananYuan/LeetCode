class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> s;
        for (auto& str : startWords) {
            int num = 0;
            for (auto c : str) {
                num |= 1 << (c - 'a');
            }
            for (int i = 0; i < 26; i += 1) {
                if ((num & (1 << i)) == 0) {
                    s.insert(num | (1 << i));
                }
            }
        }
        int ans = 0;
        for (auto& str : targetWords) {
            int num = 0;
            for (auto c : str) {
                num |= 1 << (c - 'a');
            }
            if (s.count(num)) {
                ans += 1;
            }
        }
        return ans;
    }
};
