/*#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<string> stk;
	int s_len = s.size();
	string tmp_s = "";
	string ans_s = "";
	for (int i = 0 ; i < s_len; i += 1) {
		if (s[i] == '(') {
			stk.push('(');
		}
		if (s[i] == ')') {
			string max_str_from_stk = tmp_s;
			tmp_s = "";
			while (!stk.empty()) {
				string tmp_str_from_stk = stk.top();
				stk.pop();
				if (tmp_str_from_stk.size() > max_str_from_stk.size()) {
					max_str_from_stk = tmp_str_from_stk;
				}
			}
			ans_s += max_str_from_stk;
		}
		if (s[i] == '|') {
			stk.push(tmp_s);
			tmp_s = "";
		}
		if (s[i] == 'x') {
			tmp_s += 'x';
		}
	}
	if (tmp_s != "") {
		ans_s += tmp_s;
		tmp_s = "";
	}
	cout << ans_s << "\n";
	cout << ans_s.size() << endl;
	return 0;	
}
*/

#include <iostream>
#include <stdio.h>
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
    y1 = 1998;
    m1 = 1;
    d1 = 2;
    cin >> y2;
    m2 = 1;
    d2 = 1;
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
    int tmp = 4;
    if (y2 == 1998) {
    	for (int i = 1; i <= 12; i += 1) {
    		for (int j = 1; j <= non_run[i]; j += 1) {
    			if (j == 13 && tmp == 5) {
    				printf("%d-%02d-%02d\n", y2, i, j);
				}
				tmp = (tmp + 1) % 7;
			}
		}
		return 0;
	}
	ans %= 7;
    if (is_run(y2)) {
    	for (int i = 1; i <= 12; i += 1) {
    		for (int j = 1; j <= run[i]; j += 1) {
    			if (j == 13 && ans == 0) {
    				printf("%d-%02d-%02d\n", y2, i, j);
				}
				ans = (ans + 1) % 7;
			}
		}
	}
    else {
    	for (int i = 1; i <= 12; i += 1) {
    		for (int j = 1; j <= non_run[i]; j += 1) {
    			if (j == 13 && ans == 0) {
    				printf("%d-%02d-%02d\n", y2, i, j);
				}
				ans = (ans + 1) % 7;
			}
		}
	}
    return 0;
}
