class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> line;
        string str[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (int i = 0; i < 3; i += 1) {
            for (char ch : str[i]) {
                line.insert(make_pair(ch, i));
                ch = toupper(ch);
                line.insert(make_pair(ch, i));
            }
        }
        vector<string> ans;
        for (string s : words) {
            int base_line = line[ s[0] ];
            int len = s.length();
            bool is_same = true;
            for (char ch : s) {
                if (line[ch] != base_line) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};
