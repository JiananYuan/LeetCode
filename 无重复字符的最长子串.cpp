class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int max_ans = 0;
        unordered_set<char> occur_record;
        int i = 0, j = 0;
        for (; i < len; i += 1) {
            while (j < len) {
                char ch = s[j];
                if (occur_record.count(ch) == 0) {
                    occur_record.insert(ch);
                    j += 1;
                    // update max_ans (一直无重复的情况)
                    max_ans = max(max_ans, j - i);
                }
                else {
                    // update max_ans
                    max_ans = max(max_ans, j - i);
                    // remove first element
                    occur_record.erase(s[i]);
                    break;
                }
            }
        }
        return max_ans;
        
    }
};
