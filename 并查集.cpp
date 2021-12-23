#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

namespace disjoint_set {

    class DisJoint {
    private:
        int n;
        int* data;
        map<int, int> father;
        map<int, int> ranks;

    public:
        DisJoint(int _n): n(_n) {
            data = new int[n + 1];
        }

        ~DisJoint() {
            father.clear();
            delete[] data;
            data = nullptr;
        }

        void init() {
            for (int i = 0; i < n; i += 1) {
                cin >> data[i];
                father[data[i]] = data[i];
                ranks[data[i]] = 0;
            }
        }

        int find_acs(int x) {
            /** old version
            while (x != father[x]) {
                x = father[x];
            }
            return x;
            */

            /**
            new version: 加入路径压缩算法
            */
            if (x != father[x]) {
                father[x] = find_acs(father[x]);
                return father[x];
            }
            else {
                return x;
            }
        }

        void union_set(int x, int y) {
            /** old version
            int x_acs = find_acs(x);
            int y_acs = find_acs(y);
            if (x_acs != y_acs) {
                father[x_acs] = y_acs;
            }
            */
            int x_acs = find_acs(x);
            int y_acs = find_acs(y);
            int large, small;
            if (x_acs != y_acs) {
                if (ranks[x_acs] < ranks[y_acs]) {
                    large = y_acs;
                    small = x_acs;
                }
                else {
                    large = x_acs;
                    small = y_acs;
                }
                father[small] = large;
                if (ranks[large] == ranks[small]) {
                    ranks[large] = ranks[large] + 1;
                }
            }
        }

        bool is_same_set(int x, int y) {
            int x_acs = find_acs(x);
            int y_acs = find_acs(y);
            return x_acs == y_acs;
        }

    };
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    disjoint_set::DisJoint djs(n);
    djs.init();
    cout << "1: find_acs / 2: union 2 sets / 3: is 2 ele same set\n";
    int op, x, y;
    while (cin >> op && op != -1) {
        switch (op) {
        case -1:
            break;
        case 1:
            cin >> x;
            cout << djs.find_acs(x) << endl;
            break;
        case 2:
            cin >> x >> y;
            djs.union_set(x, y);
            cout << "finished!" << endl;
            break;
        case 3:
            cin >> x >> y;
            if (djs.is_same_set(x, y)) {
                cout << "same" << endl;
            }
            else {
                cout << "different" << endl;
            }
            break;
        default:
            cout << "invalid command, try again!" << endl;
        }
        cout << "\n";
    }
    return 0;
}
