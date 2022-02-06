class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> str_vec;
        string tmp;
        stringstream ss(text);
        while (ss >> tmp) {
            str_vec.emplace_back(tmp);
        }
        int sz = int(str_vec.size());
        vector<string> ans;
        for (int i = 0; i < sz; i += 1) {
            if (str_vec[i] == first && i + 1 < sz && str_vec[i + 1] == second && i + 2 < sz) {
                ans.emplace_back(str_vec[i + 2]);
            }
        }
        return ans;
    }
};

