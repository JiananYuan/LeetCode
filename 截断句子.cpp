class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        vector<string> vec;
        for (int i = 0; i < k; i += 1) {
            ss >> word;
            vec.emplace_back(word);
        }
        string ans_string;
        for (string str : vec) {
            ans_string = ans_string + str + " ";
        }
        ans_string = ans_string.substr(0, ans_string.length() - 1);
        return ans_string;
    }
};
