// 算法：先指数查找，再二分查找

class Solution {
public:
    int binarySearch(int lo, int hi, vector<int>& nums, int& target) {
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int mid_num = nums[mid];
            if (mid_num == target) {
                return mid;
            }
            else if (mid_num < target) {
                lo = mid + 1;
            }
            else if (mid_num > target) {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        // nums is sorted
        int len = int(nums.size());
        if (len == 0 || target <= nums[0]) {
            return 0;
        }
        int i = 1;
        while (i < len && nums[i] < target) {
            i <<= 1;
        }
        int lo = i >> 1, hi = min(len-1, i);
        // cout << lo << " " << hi << endl;
        int ans = binarySearch(lo, hi, nums, target);
        return ans;
    }
};
