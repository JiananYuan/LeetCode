class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> ump;
        for (vector<int>& edge : edges) {
            int va = edge[0];
            int vb = edge[1];
            if (ump.count(va) == 0) {
                ump[va] = 1;
            }
            else {
                ump[va] += 1;
            }
            if (ump.count(vb) == 0) {
                ump[vb] = 1;
            }
            else {
                ump[vb] += 1;
            }
        }
        int max_val = -1;
        int max_id = 0;
        for (auto& p : ump) {
            if (p.second > max_val) {
                max_val = p.second;
                max_id = p.first;
            }
        }
        return max_id;
    }
};


