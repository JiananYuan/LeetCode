class Solution {
public:
    // quick multiply: a * b
    bool qm(int a, int b, int target) {
        int ans = 0;
        while (b) {
            if (b & 1) {
                if (ans < target - a) {
                    return true;
                }
                ans += a;
            }
            if (b != 1) {
                if (a < target - a) {
                    return true;
                }
                a += a;
            }
            b >>= 1;
        }
        return false;
    }

    int divide(int dividend, int divisor) {
        // special judge
        if (divisor == 0) {
            return 0x7fffffff;
        }
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return 0x7fffffff;
            }
            else if (divisor == 1) {
                return INT_MIN;
            }
        }

        bool is_minus_dividend = dividend < 0 ? true : false;
        bool is_minus_divisor = divisor < 0 ? true : false;
        if (!is_minus_dividend) {
            dividend = -dividend;
        }
        if (!is_minus_divisor) {
            divisor = -divisor;
        }
        bool is_ans_positive = (is_minus_dividend && is_minus_divisor) || (!is_minus_dividend && !is_minus_divisor);
        int i = 1, j = INT_MAX, ans = 0;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            bool overflow = qm(divisor, mid, dividend);
            if (!overflow) {
                ans = mid;
                // special: 2147483647  1
                if (mid == 0x7fffffff) {
                    break;
                }
                i = mid + 1;
            }
            // 溢出target 了
            else {
                j = mid - 1;
            }
        }
        return is_ans_positive ? ans : -ans;
    }
};
