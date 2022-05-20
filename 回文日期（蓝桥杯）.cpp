#include <iostream>
#include <algorithm>
using namespace std;

inline bool is_run(int y) {
  return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

string my_to_string(int d) {
  string rec = "";
  while (d) {
    rec = char(d % 10 + '0') + rec;
    d /= 10;
  }
  return rec;
}

inline int my_atoi(string str) {
  int len = str.length();
  int rec = 0;
  for (int i = 0; i < len; i += 1) {
    rec = rec * 10 + (str[i] - '0');
  }
  return rec;
}

int main() {
  int date_1, date_2;
  cin >> date_1 >> date_2;
  string str_date_1 = my_to_string(date_1), str_date_2 = my_to_string(date_2);
  int y_1 = date_1 / 10000, d_1 = date_1 % 100, m_1 = (date_1 - y_1 * 10000) / 100;
  int y_2 = date_2 / 10000, d_2 = date_2 % 100, m_2 = (date_2 - y_2 * 10000) / 100;
  // cout << y_1 << " " << m_1 << " " << d_1 << " " << y_2 << " " << m_2 << " " << d_2 << endl;
  const int run[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int non_run[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int ans = 0;
  for (int y = y_1; y <= y_2; y += 1) {
    string tmp = my_to_string(y);
    reverse(tmp.begin(), tmp.end());
    string date = my_to_string(y) + tmp;
    // cout << date << endl;
    int m = my_atoi(date.substr(4, 2));
    int d = my_atoi(date.substr(6, 2));
    if (m >= 1 && m <= 12) {
      if (date >= str_date_1 && date <= str_date_2) {
        if (is_run(y)) {
          if (d >= 1 && d <= run[m]) {
            ans += 1;
          }
        }
        else {
          if (d >= 1 && d <= non_run[m]) {
            ans += 1;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
