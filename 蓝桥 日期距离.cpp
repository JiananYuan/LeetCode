#include <iostream>

using namespace std;

int run[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int non_run[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool is_run(int y) {
    return (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
}

int main()
{
    int y1, m1, d1;  // 较小
    int y2, m2, d2;  // 较大
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    int tmp_d1 = y1 * 10000 + m1 * 100 + d1;
    int tmp_d2 = y2 * 10000 + m2 * 100 + d2;
    if (tmp_d1 > tmp_d2) {
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }
    int ans = 0;
    // 同年
    if (y1 == y2) {
        if (is_run(y1)) {
            if (m1 == m2) {
                ans = d2 - d1;
            }
            else {
                ans = run[m1] - d1 + d2;
                for (int i = m1 + 1; i < m2; i += 1) {
                    ans += run[i];
                }
            }
        }
        else {
            if (m1 == m2) {
                ans = d2 - d1;
            }
            else {
                ans = non_run[m1] - d1 + d2;
                for (int i = m1 + 1; i < m2; i += 1) {
                    ans += non_run[i];
                }
            }
        }
    }
    // 不同年
    else {
        if (is_run(y1)) {
            ans += run[m1] - d1;
            for (int i = m1 + 1; i <= 12; i += 1) {
                ans += run[i];
            }
        }
        else {
            ans += non_run[m1] - d1;
            for (int i = m1 + 1; i <= 12; i += 1) {
                ans += non_run[i];
            }
        }
        if (is_run(y2)) {
            ans += d2;
            for (int i = 1; i < m2; i += 1) {
                ans += run[i];
            }
        }
        else {
            ans += d2;
            for (int i = 1; i < m2; i += 1) {
                ans += non_run[i];
            }
        }
        for (int i = y1 + 1; i < y2; i += 1) {
            if (is_run(i)) {
                ans += 366;
            }
            else {
                ans += 365;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

