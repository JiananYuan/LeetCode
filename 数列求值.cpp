// 蓝桥

#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n = 20190324;
  int mod = 10000;
  int a = 1, b = 1, c = 1, d = 0;
  for (int i = 4; i <= n; i += 1) {
    d = (a + b + c) % mod;
    a = b;
    b = c;
    c = d;
  }
  cout << d << endl;
  return 0;
}
