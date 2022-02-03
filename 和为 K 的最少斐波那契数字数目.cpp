class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1, c = 0;
        const int LIMIT = 1000000000;
        vector<int> data;
        data.push_back(1);
        data.push_back(1);
        map<int, bool> mp;
        mp[1] = true;
        while (c < LIMIT) {
            c = a + b;
            a = b;
            b = c;
            data.push_back(c);
            mp[c] = true;
        }
        int ptr = upper_bound(data.begin(), data.end(), k) - data.begin() - 1;
        // cout << ptr << endl;
        int cnt = 0;
        while (ptr >= 0) {
            if (mp[k]) {
                cnt += 1;
                break;
            }
            else {
                while (data[ptr] >= k) {
                    ptr -= 1;
                }
                k -= data[ptr];
                cnt += 1;
            }
        }
        return cnt;
    }
};
