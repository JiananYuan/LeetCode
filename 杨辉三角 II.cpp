class Solution {
public:
    int data[35][35] = { 0 };

    Solution() {
        const int N = 33;
        data[1][1] = 1;
        for (int i = 2; i <= 34; i += 1) {
            for (int j = 1; j <= i; j += 1) {
                data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
            }
        }
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i = 1; i <= rowIndex + 1; i += 1) {
            ans.push_back(data[rowIndex + 1][i]);
        }
        return ans;
    }
};
