class Solution {
public:
    bool isSameAfterReversals(int num) {
        int r1 = 0;
        int _num = num;
        while (_num != 0) {
            r1 = r1 * 10 + _num % 10;
            _num /= 10;
        }
        int r2 = 0;
        while (r1 != 0) {
            r2 = r2 * 10 + r1 % 10;
            r1 /= 10;
        }
        return r2 == num;
    }
};

