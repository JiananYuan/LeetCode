class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        bool is_all_lower = true;
        int upper_cnt = 0;
        for (int i = 0; i < len; i += 1) {
            if (isupper(word[i])) {
                is_all_lower = false;
                upper_cnt += 1;
            }
        }
        // 分别对应case_1, case_2, case_3: 全大写, 全小写, 首字母大写
        return (len == upper_cnt) || is_all_lower || (upper_cnt == 1 && isupper(word[0]));
    }
};
