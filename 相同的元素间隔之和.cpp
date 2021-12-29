class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long> > mp;
        int sz = int(arr.size());
        for (int i = 0; i < sz; i += 1) {
            if (mp.count(arr[i]) == 0) {
                vector<long long> tmp;
                tmp.emplace_back(i);
                mp[arr[i]] = tmp;
            }
            else {
                mp[arr[i]].emplace_back(i);
            }
        }
        unordered_map<int, vector<long long> > qz;
        for (int i = 0; i < sz; i += 1) {
            if (qz.count(arr[i]) == 0) {
                long long sum = 0;
                vector<long long> vec(mp[arr[i]].begin(), mp[arr[i]].end());
                int ssz = int(vec.size());
                for (int i = 0; i < ssz; i += 1) {
                    sum += vec[i];
                    vec[i] = sum;
                }
                qz[arr[i]] = vec;
            }
        }
        vector<long long> ans(sz, 0);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<long long> tmp = it -> second;
            vector<long long> prefix = qz[it -> first];
            int ssz = int(tmp.size());
            for (int i = 0; i < ssz; i += 1) {
                long long sum = tmp[i] * (i + 1) - prefix[i] + (prefix[ssz - 1] - prefix[i]) - (ssz - i - 1) * tmp[i];
                ans[tmp[i]] = sum;
            }
        }
        return ans;
    }

};
