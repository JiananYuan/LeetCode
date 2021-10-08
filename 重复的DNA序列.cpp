class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vec;
        int len = s.length();
        if (len < 10) {
            return vec;
        }
        map<string, int> mp;
        for (int i = 0; i <= len - 10; i += 1) {
            string tmp_s = s.substr(i, 10);
            if (mp.count(tmp_s) == 0) {
                mp.insert(make_pair(tmp_s, 1));
            } 
            else {
                mp[tmp_s] += 1;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it -> second > 1) {
                vec.emplace_back(it -> first);
            }
        }
        return vec;
    }
};
