class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int num : nums) {
            if (num > 0) {
                pos.push_back(num);
            }
            else {
                neg.push_back(num);
            }
        }
        vector<int> ans;
        int len = int(nums.size());
        int neg_ptr = 0, pos_ptr = 0;
        for (int i = 0; i < len; i += 1) {
            if (i & 1) {
                ans.push_back(neg[neg_ptr]);
                neg_ptr += 1;
            }
            else {
                ans.push_back(pos[pos_ptr]);
                pos_ptr += 1;
            }
        }
        return ans;
    }
};
