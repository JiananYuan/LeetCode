class Solution {
public:
    map<int, int> getBitNum(int n) {
        map<int, int> n_mp;
        while (n != 0) {
            int rear_num = n % 10;
            if (n_mp.count(rear_num) != 0) {
                n_mp[rear_num] += 1;
            }
            else {
                n_mp.insert(make_pair(rear_num, 1));
            }
            n /= 10;
        }
        return n_mp;
    }

    bool reorderedPowerOf2(int n) {
        set<map<int, int> > st;
        for (int i = 0; i < 32; i += 1) {
            int num = 1 << i;
            map<int, int> mp = getBitNum(num);
            st.insert(mp);
        }
        map<int, int> n_mp = getBitNum(n);
        return st.count(n_mp) == 1 ? true : false;
    }
};
