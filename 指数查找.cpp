#include <iostream>
using namespace std;

int main() {
    // int a[] = {0, 3, 4, 10, 100, 233, 500, 1000, 1001, 1001, 1002};
    int a[] = { 0, 1 };
    int x, n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i += 1) {
        cout << a[i] << " ";
    }
    cout << endl;
    while (cin >> x) {
        int i = 0, base = 0;
        while (true) {
            int index = base + (1 << i);
            if (index >= n) {
                base = base + (1 << (i - 1));
                i = 0;
                index = base + (1 << i);
            }
            if (base >= n || index >= n) {
                cout << "not found" << endl;
                break;
            }
            int num = a[index];
            if (x == num) {
                cout << "locate at " << index << endl;
                break;
            }
            else if (x > num) {
                i += 1;
            }
            else {
                if (i == 0) {
                    cout << "not found" << endl;
                    break;
                }
                base = base + (1 << (i - 1));
                i = 0;
            }
        }
    }
    return 0;
}
