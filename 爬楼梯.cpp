class Solution {
public:
    int mem[50] = { 0 };

    int climb(int n) {
        if (mem[n]) {
            return mem[n];
        }
        if (n <= 1) {
            return 1;
        }
        mem[n] = climb(n - 1) + climb(n - 2);
        return mem[n];
    }

    int climbStairs(int n) {
        mem[1] = 1;
        mem[2] = 2;
        return climb(n);
    }
};
