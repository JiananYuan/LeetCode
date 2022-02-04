class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> mp;
        int maxx = 0;
        for (vector<int>& rec : rectangles) {
            int minx = min(rec[0], rec[1]);
            maxx = max(maxx, minx);
            mp[minx] += 1;
        }
        return mp[maxx];
    }
};
