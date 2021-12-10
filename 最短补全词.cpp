/*
给你一个字符串 licensePlate 和一个字符串数组 words ，请你找出并返回 words 中的 最短补全词 。

补全词 是一个包含 licensePlate 中所有的字母的单词。在所有补全词中，最短的那个就是 最短补全词 。

在匹配 licensePlate 中的字母时：

忽略 licensePlate 中的 数字和空格 。
不区分大小写。
如果某个字母在 licensePlate 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。
例如：licensePlate = "aBc 12c"，那么它的补全词应当包含字母 'a'、'b' （忽略大写）和两个 'c' 。可能的 补全词 有 "abccdef"、"caaacab" 以及 "cbca" 。

请你找出并返回 words 中的 最短补全词 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 words 中 最靠前的 那个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-completing-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:


    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int licensePlate_len = licensePlate.length();
        int char_cnt[26] = { 0 };
        for (int i = 0; i < licensePlate_len; i += 1) {
            char ch = licensePlate[i];
            if (isChar(ch)) {
                ch = to_lower(ch);
                char_cnt[ ch - 'a' ] += 1;
            }
        }
        int vec_len = int(words.size());
        string shorest_ans = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
        for (int i = 0; i < vec_len; i += 1) {
            if (contain(char_cnt, words[i])) {
                if (words[i].length() < shorest_ans.length()) {
                    shorest_ans = words[i];
                }
            }
        }
        return shorest_ans;
    }

    // tool func
    bool isChar(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    // tool func
    char to_lower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        return ch;
    }

    // str_cnt contain bench?
    bool contain(int bench_cnt[], string str) {
        int str_len = str.length();
        int char_cnt[26] = { 0 };
        for (int i = 0; i < str_len; i += 1) {
            char ch = str[i];
            if (isChar(ch)) {
                ch = to_lower(ch);
                char_cnt[ ch - 'a' ] += 1;
            }
        }
        for (int i = 0; i < 26; i += 1) {
            if (bench_cnt[i] > char_cnt[i]) {
                return false;
            }
        }
        return true;
    }

};
