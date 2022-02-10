class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int len = tmp.size();
        int minx = 0x7fffffff;
        for (int i = k - 1; i < len; i += 1) {
            minx = min(minx, tmp[i] - tmp[i - k + 1]);
        }
        return minx;
    }
};
