class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for (int num : nums) {
            record[num] += 1;
        }
        set<pair<int, int> > ans;
        for (int num : nums) {
            int target = num - k;
            if (k != 0 && record[target] > 0) {
                ans.insert({ target, num });
            }
            else if (k == 0 && record[target] > 1) {
                ans.insert({ target, num });
            }
        }
        return ans.size();
    }
};
