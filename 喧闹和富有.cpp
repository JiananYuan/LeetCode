struct node {
    int id;
    int richer_rank;
    int quiet;
    node(int _id = 0, int _richer_rank = 0, int _quiet = 0) {
        id = _id;
        richer_rank = _richer_rank;
        quiet = _quiet;
    }
};

class Solution {
public:

    vector<vector<int> > ranks(520);

    static bool cmp(node& a, node& b) {
        return a.richer_rank < b.richer_rank;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        ranks.clear();
        int richer_len = int(richer.size());
        int quiet_len = int(quiet.size());
        // 初始化富豪榜
        vector<node> richer_rank;
        for (int i = 0; i < quiet_len; i += 1) {
            richer_rank.emplace_back(node(i, 0, quiet[i]));
        }
        // 拉链法求名次
        for (int i = 0; i < richer_len; i += 1) {
            ranks[ richer[i][0] ].push_back(richer[i][1]);
        }
        // to be continued...
        for (int i = 0; i < richer_len; i += 1) {
            richer_rank[ richer[i][1] ].richer_rank += 1;
        }
        sort(richer_rank.begin(), richer_rank.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < quiet_len; i += 1) {
            int most_quiet = 1000;
            int most_quiet_id = i;
            for (int j = i - 1; j >= 0; j -= 1) {
                if (most_quiet > richer_rank[j].quiet) {
                    most_quiet = richer_rank[j].quiet;
                    most_quiet_id = richer_rank[j].id;
                }
            }
            ans.push_back(most_quiet_id);
        }
        return ans;
    }
};
