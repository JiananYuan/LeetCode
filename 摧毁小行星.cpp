class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        int sz = int(asteroids.size());
        for (int i = 0; i < sz; i += 1) {
            if (m >= asteroids[i]) {
                m += asteroids[i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
