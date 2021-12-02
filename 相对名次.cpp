class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> score_copy(score);
        sort(score_copy.begin(), score_copy.end(), greater<int>());
        int len = int(score.size());
        map<int, int> mp;
        for (int i = 0; i < len; i += 1) {
            mp.insert(make_pair(score_copy[i], i + 1));
        }
        vector<string> rank;
        for (int i = 0; i < len; i += 1) {
            rank.emplace_back(to_string(mp[ score[i] ]));
            switch (mp[ score[i] ]) {
                case 1:
                    rank[i] = "Gold Medal";
                    break;
                case 2:
                    rank[i] = "Silver Medal";
                    break;
                case 3:
                    rank[i] = "Bronze Medal";
                    break;
            }
        }
        return rank;
    }
};
