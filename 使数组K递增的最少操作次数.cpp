class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int arr_len = int(arr.size());
        int ans = 0;
        for (int i = 0; i < k; i += 1) {
            vector<int> vec;
            for (int j = i; j < arr_len; j += k) {
                vec.push_back(arr[j]);
            }
            ans += int(vec.size()) - maxIncrease(vec);
        }
        return ans;
    }

    int maxIncrease(vector<int>& vec) {
        int len = 1, n = int(vec.size());
        int* d = new int[n + 1];
        d[len] = vec[0];
        for (int i = 1; i < n; i += 1) {
            if (vec[i] >= d[len]) {
                d[++len] = vec[i];
            }
            // vec[i] < d[len]
            else {
                int pos = upper_bound(d, d + len, vec[i]) - d;
                d[pos] = vec[i];
            }
        }
        delete[] d;
        return len;
    }
};
