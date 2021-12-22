class Solution {
public:
    
    int kIncreasing(vector<int>& arr, int k) {
        int len = int(arr.size());
        int ans = 0;
        for (int i = 0; i < k; i += 1) {
            vector<int> vec;
            for (int j = i; j < len; j += k) {
                vec.push_back(arr[j]);
            }
            ans += int(vec.size()) - maxLongestIncreaseSegment(vec);
        }    
        return ans;
    }

    int maxLongestIncreaseSegment(vector<int>& arr) {
        int len = int(arr.size());
        int* dp = new int[len + 1];
        dp[1] = arr[0];
        int rightMost = 1;
        for (int i = 1; i < len; i += 1) {
            if (arr[i] >= dp[rightMost]) {
                dp[++rightMost] = arr[i];
            }
            else {
                int pos = upper_bound(dp + 1, dp + 1 + rightMost, arr[i]) - dp;
                dp[pos] = arr[i];
            }
        }
        delete[] dp;
        return rightMost;
    }

};
