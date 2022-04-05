class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        int len = nums.size();
        for (int i = 0; i < len; i += 1) {
            if (i & 1) {
                odd.push_back(nums[i]);
            }
            else {
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        vector<int> ans;
        int o = 0, e = 0;
        for (int i = 0; i < len; i += 1) {
            if (i & 1) {
                ans.push_back(odd[o++]);
            }
            else {
                ans.push_back(even[e++]);
            }
        }
        return ans;
    }
};

