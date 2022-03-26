class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<map<char, int> > st;
        map<map<char, int>, int> mp;
        vector<vector<string> > ans;
        int strs_len = int(strs.size());
        for (int i = 0; i < strs_len; i += 1) {
            string tmp_s = strs[i];
            map<char, int> tmp_mp;
            int len = tmp_s.length();
            for (int j = 0; j < len; j += 1) {
                if (tmp_mp.count(tmp_s[j])) {
                    tmp_mp[tmp_s[j]] += 1;
                }
                else {
                    tmp_mp.insert(make_pair(tmp_s[j], 1));
                }
            }
            if (st.count(tmp_mp)) {
                ans[ mp[tmp_mp] ].emplace_back(tmp_s);
            }
            else {
                vector<string> tmp;
                tmp.emplace_back(tmp_s);
                ans.emplace_back(tmp);
                mp.insert(make_pair(tmp_mp, int(ans.size()) - 1));
                st.insert(tmp_mp); 
            }
        }
        return ans;
    }
};

