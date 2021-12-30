class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = int(nums.size());
        for (int i = 1; i < sz; i += 1) {
            if (nums[0] == nums[i] || (nums[i] - nums[0]) % 2 != 0) {
                continue;
            }
            int k = (nums[i] - nums[0]) >> 1;
            vector<bool> used(sz, false);
            used[0] = used[i] = true;
            int left = 0, right = i + 1;
            vector<int> ans;
            ans.push_back(nums[0] + k);
            for (int j = 1; j < sz / 2; j += 1) {
                while (used[left]) {
                    left += 1;
                }
                while (right < sz && (used[right] || nums[right] - nums[left] != 2 * k)) {
                    right += 1;
                }
                if (right >= sz) {
                    break;
                }
                ans.push_back(nums[left] + k);
                used[left] = used[right] = true;
            }
            if (int(ans.size()) == sz / 2) {
                return ans;
            }
        }
        return {};
    }
};
