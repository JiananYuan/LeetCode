class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int sum = 1;
        int st = sqrt(num);
        for (int i = 2; i <= st; i += 1) {
            if (num % i == 0) {
                sum += i;
                int b = num / i;
                if (i != b) {
                    sum += (num / i);
                }
            }
        }
        // cout << sum << endl;
        if (sum == num) {
            return true;
        }
        return false;
    }
};
