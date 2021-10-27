class Solution {
public:
    static const int N = 10;
    bool mark[N];
    vector<vector<int>> ans;

    void traverse(vector<int>& nums, vector<int>& tmp, int index, int& len) {
        if (index == len) {
            ans.emplace_back(tmp);
            return;
        }

        for (int i = 0; i < len; i += 1) {
            if (mark[i]) {
                continue;
            }
            mark[i] = true;
            tmp.push_back(nums[i]);
            traverse(nums, tmp, index + 1, len);
            tmp.pop_back();
            mark[i] = false;
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        int len = int(nums.size());
        traverse(nums, tmp, 0, len);
        return ans;
    }
};
