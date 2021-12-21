class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = int(nums.size());
        int* dp = new int[len + 1];
        // dp[i]表示前i个数组成的序列中，增长幅度最小的数
        dp[1] = nums[0];
        int max_right = 1;
        for (int i = 1; i < len; i += 1) {
            if (nums[i] > dp[max_right]) {
                max_right += 1;
                dp[max_right] = nums[i];
            }
            else {
                int pos = lower_bound(dp + 1, dp + 1 + max_right, nums[i]) - dp;
                dp[pos] = nums[i];
            }
        }
        delete[] dp;
        return max_right;
    }
};
