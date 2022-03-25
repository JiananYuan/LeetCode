class Solution {
public:
    /*
        ranks[0] = [...]  // 0比后面一串人贫穷
    */
    vector<set<int> > ranks;

    // father = 1, child = 2
    void auto_add(int father, int child) {
        // 两方面考虑
        int len = int(ranks.size());
        for (int i = 0; i < len; i += 1) {
            if (ranks[i].count(father) != 0) {
                ranks[i].insert(child);
            }
        }
        for (auto it = ranks[child].begin(); it != ranks[child].end(); it++) {
            if (ranks[father].count(*it) == 0) {
                ranks[father].insert(*it);
                auto_add(father, *it);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        ranks.clear();
        int len_richer = int(richer.size());
        int len_quiet = int(quiet.size());
        for (int i = 0; i < len_quiet; i += 1) {
            ranks.emplace_back(set<int>());
        }
        for (int i = 0; i < len_richer; i += 1) {
            if (ranks[ richer[i][1] ].count(richer[i][0]) == 0) {
                ranks[ richer[i][1] ].insert(richer[i][0]);
                auto_add(richer[i][1], richer[i][0]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < len_quiet; i += 1) {
            set<int> s = ranks[i];
            int quiet_val = quiet[i];
            int quiet_id = i;
            for (auto it = s.begin(); it != s.end(); it++) {
                if (quiet[*it] < quiet_val) {
                    quiet_val = quiet[*it];
                    quiet_id = *it;
                }
            }
            ans.push_back(quiet_id);
        }
        return ans;
    }
};

