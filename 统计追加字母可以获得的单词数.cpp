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


// TLE solution
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        sort(startWords.begin(), startWords.end());
        startWords.erase(unique(startWords.begin(), startWords.end()), startWords.end());
        int s_len = int(startWords.size());
        int t_len = int(targetWords.size());
        int ans = 0;
        vector<vector<int> > sw_map(s_len, vector<int>());
        for (int i = 0; i < s_len; i += 1) {
            sw_map[i].assign(26, 0);
        }
        for (int j = 0; j < s_len; j += 1) {
            int w_len = startWords[j].length();
            for (int k = 0; k < w_len; k += 1) {
                sw_map[j][startWords[j][k] - 'a'] += 1;
            }
        }
        for (int i = 0; i < t_len; i += 1) {
            int tw_len = targetWords[i].length();
            int tw_map[26] = { 0 };
            for (int k = 0; k < tw_len; k += 1) {
                tw_map[targetWords[i][k] - 'a'] += 1;
            }
            for (int j = 0; j < s_len; j += 1) {
                int sw_len = startWords[j].length();
                if (tw_len - sw_len != 1) {
                    continue;
                }
                bool first_diff = true;
                bool can = true;
                for (int k = 0; k < 26; k += 1) {
                    if (tw_map[k] != sw_map[j][k] && !first_diff) {
                        can = false;
                        break;
                    }
                    if (tw_map[k] == 1 && sw_map[j][k] == 0 && first_diff) {
                        first_diff = false;
                    }
                }
                if (can) {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }
};
