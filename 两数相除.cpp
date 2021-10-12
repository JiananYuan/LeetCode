class Solution {
public:
    // quick multiply: a * b
    int qm(int a, int b) {
        int ans = 0;
        while (b) {
            if (b & 1) {
                ans += a;
            }
            b >>= 1;
            a <<= 1;
        }
        return ans;
    }
    
    int divide(int dividend, int divisor) {
        // special judge
        if (dividend == -2147483648) {
            return 0x7fffffff;
        }
        if (abs(dividend) < abs(divisor)) {
            return 0;
        }
        bool is_minus_dividend = dividend < 0 ? true : false;
        bool is_minus_divisor = divisor < 0 ? true : false;
        if (is_minus_dividend) {
            dividend = -dividend;
        }
        if (is_minus_divisor) {
            divisor = -divisor;
        }
        bool is_ans_positive = (is_minus_dividend && is_minus_divisor) || (!is_minus_dividend && !is_minus_divisor);
        long i = 1, j = dividend;
        while (i <= j) {
            int mid = (i + j) >> 1;
            // int mid = (i >> 1) + (j >> 1);
            int ans = qm(mid, divisor);
            if (ans == dividend) {
                // return mid;
                j = mid;
                break;
            }
            else if (ans < dividend) {
                i = mid + 1;
            }
            else if (ans > dividend) {
                j = mid - 1;
            }
        }
        return is_ans_positive ? j : -j; 
    }
};
