class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> v1;
        vector<int> v2;
        int len = words.size();
        for (int i = 0; i < len; i += 1) {
            if (words[i] == word1) {
                v1.push_back(i);
            }
            if (words[i] == word2) {
                v2.push_back(i);
            }
        }
        int minx = 0x77ffffff;
        int v1_len = v1.size();
        int v2_len = v2.size();
        for (int i = 0; i < v1_len; i += 1) {
            for (int j = 0; j < v2_len; j += 1) {
                int dis = abs(v1[i] - v2[j]);
                if (dis < minx) {
                    minx = dis;
                }
                else {
                    
                }
            }
        }
        return minx;
    }
};
