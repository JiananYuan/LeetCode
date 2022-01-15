class Solution {
public:
    int totalMoney(int n) {
        int m = n / 7;
        int sum_1 = 7 * (m * (1 + m) / 2 + m * (7 + (7 + m - 1)) / 2) / 2;
        int sum_2 = 0;
        for (int i = m + 1; i <= m + n % 7; i += 1) {
            sum_2 += i;
        }
        return sum_1 + sum_2;
    }
};
