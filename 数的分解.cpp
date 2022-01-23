// 蓝桥杯

#include <iostream>
#include <set>
using namespace std;

set<set<int> > s;
const int TARGET = 2019;
bool mark[TARGET + 5] = { false };

inline bool check(int num) {
  while (num) {
    int r = num % 10;
    num /= 10;
    if (r == 2 || r == 4) {
      return false;
    }
  }
  return true;
}

int cnt = 0;

void dfs(int remain, int current, int current_sum, set<int> tmp_s) {
  if (current == 3) {
    if (current_sum == TARGET) {
        s.insert(tmp_s);
    }
    return;
  }
  for (int i = 1; i <= remain; i += 1) {
    if (current_sum + i > TARGET) {
        break;
    }
    if (current == 2) {
        if (check(TARGET - current_sum) && !mark[TARGET - current_sum]) {
            // cnt += 1;
            tmp_s.insert(TARGET - current_sum);
            dfs(0, 3, TARGET, tmp_s);
            tmp_s.erase(TARGET - current_sum);
        }
        return;
    }
    if (check(i) && !mark[i]) {
      tmp_s.insert(i);
      mark[i] = true;
      dfs(remain - i, current + 1, current_sum + i, tmp_s);
      mark[i] = false;
      tmp_s.erase(i);
    }
  }
//   cout << "finish" << endl;
}

int main()
{
  // 请在此输入您的代码
  set<int> tmp_s;
  dfs(TARGET, 0, 0, tmp_s);
  cout << int(s.size()) << endl;
  return 0;
}
