class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = int(words.size());
        vector<int> mask;
        for (int i = 0; i < len; i += 1) {
            int mask_num = 0;
            for (char ch : words[i]) {
                mask_num = mask_num | (1 << (ch - 'a'));
            }
            mask.push_back(mask_num);
        }
        int ans = 0;
        for (int i = 0; i < len; i += 1) {
            for (int j = i + 1; j < len; j += 1) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
