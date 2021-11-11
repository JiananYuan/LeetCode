class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > anss;
        int length = int(nums.size());
        bool visit[10] = {0};
        vector<int> current;
        solve(nums, length, visit, current, anss);
        vector<vector<int> > ans;
        for (auto it = anss.begin(); it != anss.end(); it++) {
            ans.emplace_back(*it);
        }
        return ans;
    }

    void solve(vector<int>& nums, int& length, bool visit[], vector<int>& current, set<vector<int> >& ans) {
        if (int(current.size()) == length) {
            ans.insert(current);
            return;
        }
        for (int i = 0; i < length; i += 1) {
            if (visit[i] == false) {
                visit[i] = true;
                current.push_back(nums[i]);
                solve(nums, length, visit, current, ans);
                current.pop_back();
                visit[i] = false;
            }
        }
    }

};
