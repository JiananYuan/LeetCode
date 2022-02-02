class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = 0;
        int len = word.length();
        while (j < len && word[j] != ch) {
            j += 1;
        }
        if (j != len) {
            int i = 0;
            while (i < j) {
                swap(word[i], word[j]);
                i += 1;
                j -= 1;
            }
        }
        return word;
    }
};
