class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> cnt_map;
        for (char ch : s) {
            if (cnt_map.count(ch) == 0) {
                cnt_map[ch] = 1;
            }
            else {
                cnt_map[ch] = cnt_map[ch] + 1;
            }
        }
        int ans = 0;
        while (true) {
            bool not_enough = false;
            for (char ch : target) {
                if (cnt_map[ch] > 0) {
                    cnt_map[ch] -= 1;
                }
                else {
                    not_enough = true;
                    break;
                }
            }
            if (not_enough) {
                break;
            }
            ans += 1;
        }
        return ans;
    }
};
