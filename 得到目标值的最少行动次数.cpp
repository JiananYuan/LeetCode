class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if (maxDoubles == 0) {
            return target - 1;
        }
        int ans = 0;
        while (target != 1) {
            ans += 1;
            if ((target & 1) == 0 && maxDoubles > 0) {
                target >>= 1;
                maxDoubles -= 1;
            }
            else {
                target -= 1;
            }
        }
        return ans;
    }
};

