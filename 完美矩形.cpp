typedef pair<int, int> Point;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minx = 0x7fffffff, miny = 0x7fffffff;
        int maxa = 0x80000000, maxb = 0x80000000;
        long total_area = 0;
        map<Point, int> mp;
        for (auto& rec : rectangles) {
            minx = min(minx, rec[0]);
            miny = min(miny, rec[1]);
            maxa = max(maxa, rec[2]);
            maxb = max(maxb, rec[3]);
            total_area += (long)(rec[2] - rec[0]) * (long)(rec[3] - rec[1]);
            mp[Point(rec[0], rec[1])] += 1;
            mp[Point(rec[2], rec[3])] += 1;
            mp[Point(rec[0], rec[3])] += 1;
            mp[Point(rec[2], rec[1])] += 1;
        }
        if (total_area != (long)(maxa - minx) * (long)(maxb - miny) || 
            !mp.count(Point(minx, miny)) || !mp.count(Point(minx, maxb)) || 
            !mp.count(Point(maxa, miny)) || !mp.count(Point(maxa, maxb))) {
                return false;
            }
        mp.erase(Point(minx, miny));
        mp.erase(Point(minx, maxb));
        mp.erase(Point(maxa, miny));
        mp.erase(Point(maxa, maxb));
        for (auto& point : mp) {
            int cnt = point.second;
            if (cnt != 2 && cnt != 4) {
                return false;
            }
        }
        return true;
    }
};
