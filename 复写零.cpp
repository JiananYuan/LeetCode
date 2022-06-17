class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int pos = 0;
        int len = arr.size();
        while (pos < len) {
            if (arr[pos] == 0) {
                arr.insert(arr.begin() + pos + 1, 0);
                pos += 2;
                continue;
            }
            pos += 1;
        }
        arr.resize(len);
    }
};
