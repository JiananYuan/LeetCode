class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = int(nums.size());
        int minx = nums[0], maxx = nums[len - 1];
        int ans = 0;
        for (int i = 0; i < len; i += 1) {
            if (nums[i] > minx && nums[i] < maxx) {
                ans += 1;
            }
        }
        return ans;
    }
};

