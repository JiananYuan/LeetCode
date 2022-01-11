struct flower {
    int plantTime;
    int growTime;
    flower(int _plantTime, int _growTime) {
        plantTime = _plantTime;
        growTime = _growTime;
    }
};

bool cmp(flower& x, flower& y) {
    return x.growTime > y.growTime;
}

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<flower> vec;
        int sz = int(plantTime.size());
        for (int i = 0; i < sz; i += 1) {
            vec.emplace_back(flower(plantTime[i], growTime[i]));
        }
        sort(vec.begin(), vec.end(), cmp);
        int ans = 0, day = 0;
        for (int i = 0; i < sz; i += 1) {
            day += vec[i].plantTime;
            ans = max(ans, day + vec[i].growTime);
        }
        return ans;
    }
};
