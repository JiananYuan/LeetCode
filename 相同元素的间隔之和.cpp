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
        // for (int i = 0; i < sz; i += 1) {
        //     vector<long long> vec = mp[arr[i]];
        //     for (auto item : vec) {
        //         cout << item << " ";
        //     }
        //     cout << endl;
        // }
        // 求前缀和
        unordered_map<int, vector<long long> > qz;
        for (int i = 0; i < sz; i += 1) {
            if (qz.count(arr[i]) == 0) {
                long long sum = 0;
                vector<long long> vec(mp[arr[i]].begin(), mp[arr[i]].end());
                // for (auto item : vec) {
                //     cout << item << " ";
                // }
                // cout << endl;
                int ssz = int(vec.size());
                // cout << "size: " << ssz << endl;
                for (int i = 0; i < ssz; i += 1) {
                    sum += vec[i];
                    vec[i] = sum;
                    // cout << vec[i] << " ";
                }
                // cout << endl;
                qz[arr[i]] = vec;
            }
        }
        vector<long long> ans;
        for (int i = 0; i < sz; i += 1) {
            int num = arr[i];
            vector<long long> tmp = mp[num];
            int pos = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
            cout << pos << endl;
            vector<long long> qqz = qz[num];
            long long sum = i * (pos - 1) - qqz[pos - 1] + (qqz[qqz.size() - 1] - qqz[pos]) - (tmp.size() - pos) * i;
            ans.emplace_back(sum);
        }
        return ans;
    }
    
    // inline long long myabs(int x) {
    //     if (x < 0) {
    //         return (long long)(-x);
    //     }
    //     else {
    //         return (long long)(x);
    //     }
    // }
};
