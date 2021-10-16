class Solution {
public:
    map<char, vector<char> >mp;
    vector<string> vec;

    Solution() {
        mp.insert(make_pair('2', vector<char>({'a', 'b', 'c'})));
        mp.insert(make_pair('3', vector<char>({'d', 'e', 'f'})));
        mp.insert(make_pair('4', vector<char>({'g', 'h', 'i'})));
        mp.insert(make_pair('5', vector<char>({'j', 'k', 'l'})));
        mp.insert(make_pair('6', vector<char>({'m', 'n', 'o'})));
        mp.insert(make_pair('7', vector<char>({'p', 'q', 'r', 's'})));
        mp.insert(make_pair('8', vector<char>({'t', 'u', 'v'})));
        mp.insert(make_pair('9', vector<char>({'w', 'x', 'y', 'z'})));
    }

    void solve(string digits, int index, string str) {
        if (index >= digits.length()) {
            if (str != "") {
                vec.emplace_back(str);
            }
            return;
        }
        vector<char> arr = mp[digits[index]];
        int arr_len = int(arr.size());
        for (int i = 0; i < arr_len; i += 1) {
            char ch = arr[i];
            solve(digits, index + 1, str + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        string str = "";
        solve(digits, 0, str);
        return vec;
    }
};
