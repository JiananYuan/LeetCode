struct node {
    int up;
    int down;
    node(int _up, int _down) {
        up = _up;
        down = _down;
    }
};

bool cmp(const node& x, const node& y) {
    return double(x.up) / x.down < double(y.up) / y.down;
}

class Solution {
public:
    vector<node> vec;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vec.clear();
        int len = int(arr.size());
        for (int i = 0; i < len; i += 1) {
            for (int j = i + 1; j < len;j += 1) {
                vec.push_back(node(arr[i], arr[j]));
            }
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans(2);
        ans[0] = vec[k - 1].up;
        ans[1] = vec[k - 1].down;
        return ans;
    }
};
