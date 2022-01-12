class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // cnt: number of zero
        int cnt = accumulate(nums.begin(), nums.end(), 0);
        int sz = int(nums.size());
        // three cases no need to swap
        if (cnt == sz || cnt == 0 || cnt == 1) {
            return 0;
        }
        int j = 0;
        int window = 0;
        int ans = int(nums.size());
        for (int i = 0; i < sz; i += 1) {
            while (true) {
                int x = (i > j) ? sz + j : j;
                if (x >= i + cnt) break;
                window += nums[j];
                j = (j + 1 == sz) ? 0 : j + 1;
            }
            ans = min(ans, cnt - window);
            window -= nums[i];
        }
        return ans;
    }
};
