class Solution {
public:
    int arrangeCoins(int n) {
        long long nn = n;
        return int((-1 + sqrt(1 + 8 * nn)) / 2);
    }
};
