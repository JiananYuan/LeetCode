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

// Solution_2: 
class Solution {
    public int minSwaps(int[] nums) {
        int len = nums.length, o = 0, res = Integer.MAX_VALUE;
        //统计1的个数
        for (int i : nums) {
            o += i;
        }
        int l = 0, r = 0, count = 0;
        //窗口左边界为0，将右边界移动到 o-1处，使窗口大小为o
        while (r < o - 1){
            count += nums[r++]; //计算窗口中1的个数
        }
        //因为是环形数组，所以得窗口左边界一直移动到数组末尾，才能结束
        while (l < len){
            count += nums[r++ % len];
            res = Math.min(res, o - count); //o-count：窗口中0的个数
            count -= nums[l++]; //左边界右移一位
        }
        return res;
    }
}
