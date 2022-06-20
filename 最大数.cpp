class Solution {
public:
    static bool cmp(int x, int y) {
        return to_string(x) + to_string(y) > to_string(y) + to_string(x);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for (int item : nums) {
            ans += to_string(item);
        }
        for (int i = 0; i < ans.size(); i += 1) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
};
