class Solution {
public:
    // quick multiply: a * b
    long qm(long a, long b) {
        long ans = 0;
        while (b) {
            if (b & 1) {
                ans += a;
            }
            b >>= 1;
            a <<= 1;
        }
        return ans;
    }
    
    int divide(int _dividend, int _divisor) {
        long dividend = _dividend, divisor = _divisor;
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
        if (abs(dividend) < abs(divisor)) {
            return 0;
        }
        // ===
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
            long mid = (i + j) >> 1;
            long ans = qm(mid, divisor);
            if (ans == dividend) {
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
