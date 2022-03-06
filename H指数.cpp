class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int citations_len = int(citations.size());
        int h_index = -1;
        for (int i = 0; i < citations_len; i += 1) {
            h_index = max(h_index, min(citations[i], citations_len - i));
        }
        return h_index;
    }
};

