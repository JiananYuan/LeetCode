class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = int(matrix.size());
        for (int i = 0; i < n; i += 1) {
            if (!checkRow(matrix, i)) {
                return false;
            }
            if (!checkCol(matrix, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool checkRow(vector<vector<int>>& matrix, int row) {
        unordered_set<int> s;
        int sz = int(matrix[row].size());
        for (int i = 0; i < sz; i += 1) {
            s.insert(matrix[row][i]);
        }
        return checkContain(sz, s);
    }
    
    bool checkCol(vector<vector<int>>& matrix, int col) {
        unordered_set<int> s;
        int sz = int(matrix.size());
        for (int i = 0; i < sz; i += 1) {
            s.insert(matrix[i][col]);    
        }
        return checkContain(sz, s);
    }
    
    inline bool checkContain(int sz, unordered_set<int>& s) {
        for (int i = 1; i <= sz; i += 1) {
            if (!s.count(i)) {
                return false;
            }
        }
        return true;
    }
};
