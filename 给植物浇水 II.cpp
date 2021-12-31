class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = int(plants.size()) - 1;
        int cnt = 0, rA = capacityA, rB = capacityB;
        while (i < j) {
            if (plants[i] <= rA) {
                rA -= plants[i];
                i += 1;
            }
            else {
                rA = capacityA;
                cnt += 1;
                rA -= plants[i];
                i += 1;
            }
            if (plants[j] <= rB) {
                rB -= plants[j];
                j -= 1;
            }
            else {
                rB = capacityB;
                cnt += 1;
                rB -= plants[j];
                j -= 1;
            }
        }
        if (i == j) {
            if (rA >= rB) {
                if (rA < plants[i]) {
                    cnt += 1;
                }
            }
            else {
                if (rB < plants[i]) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
