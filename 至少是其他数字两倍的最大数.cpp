class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int sz = int(nums.size());
        int maxx = -1;
        int maxx_id = -1;
        for (int i = 0; i < sz; i += 1) {
            if (maxx < nums[i]) {
                maxx = nums[i];
                maxx_id = i;
            }
        }
        // cout << maxx_id << endl;
        for (int num : nums) {
            // cout << (num << 1) << endl;
            if (num != maxx && (num << 1) > maxx) {
                return -1;
            }
        }
        return maxx_id;
    }
};
