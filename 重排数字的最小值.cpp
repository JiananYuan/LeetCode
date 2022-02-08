class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        vector<int> vec;
        long long n = num;
        while (n) {
            int r = n % 10;
            if (r < 0) {
                r = -r;
            }
            vec.push_back(r);
            n /= 10;
        }
        int len = vec.size();
        sort(vec.begin(), vec.end());
        if (num >= 0) {
            int cnt0 = 0;
            while (cnt0 < len && vec[cnt0] == 0) {
                cnt0 += 1;
            }
            long long ans = vec[cnt0];
            for (int i = 0; i <= cnt0 - 1; i += 1) {
                ans = ans * 10;
            }
            for (int i = cnt0 + 1; i < len; i += 1) {
                ans = ans * 10 + vec[i];
            }
            return ans;
        }
        else {
            reverse(vec.begin(), vec.end());
            long long ans = 0;
            for (int i = 0; i < len; i += 1) {
                ans = ans * 10 + vec[i];
            }
            return -ans;
        }
    }
};
