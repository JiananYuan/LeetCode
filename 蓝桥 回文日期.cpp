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

inline bool is_huiwen(string s) {
	return s[0] == s[7] && s[1] == s[6] && s[2] == s[5] && s[3] == s[4];
}

string my_to_string(int d) {
	string rec = "";
	while (d) {
		rec = char((d % 10) + '0') + rec;
		d /= 10;
	}
	return rec;
}

int main()
{
    int date_1, date_2;
	cin >> date_1 >> date_2;
	string dd_1 = my_to_string(date_1), dd_2 = my_to_string(date_2);
	int y_1 = date_1 / 10000, d_1 = date_1 % 100, m_1 = (date_1 - y_1 * 10000) / 100;
	int y_2 = date_2 / 10000, d_2 = date_2 % 100, m_2 = (date_2 - y_2 * 10000) / 100;
	int ans = 0;
	for (int i = y_1; i <= y_2; i += 1) {
		for (int j = 1; j <= 12; j += 1) {
			if (is_run(i)) {
				for (int k = 1; k <= run[j]; k += 1) {
					string str = my_to_string(i);
					if (j < 10) {
						str = str + "0" + my_to_string(j);
					}
					else {
						str = str + my_to_string(j);
					}
					if (k < 10) {
						str = str + "0" + my_to_string(k);
					}
					else {
						str = str + my_to_string(k);
					}
					if (str >= dd_1 && str <= dd_2 && is_huiwen(str)) {
						ans += 1;
					}
				}
			}
			else {
				for (int k = 1; k <= non_run[j]; k += 1) {
					string str = my_to_string(i);
					if (j < 10) {
						str = str + "0" + my_to_string(j);
					}
					else {
						str = str + my_to_string(j);
					}
					if (k < 10) {
						str = str + "0" + my_to_string(k);
					}
					else {
						str = str + my_to_string(k);
					}
					if (str >= dd_1 && str <= dd_2 && is_huiwen(str)) {
						ans += 1;
					}
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}
