#include <iostream>
#include <algorithm>
using namespace std;

const int N = 102;

int main()
{
  int triangle[N][N];
  int dp[N][N];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= i; j += 1) {
      cin >> triangle[i][j];
    }
  }
  // init dp array
  for (int i = 1; i <= n; i += 1) {
    dp[n][i] = triangle[n][i];
  }
  for (int i = n - 1; i >= 1; i -= 1) {
    for (int j = 1; j <= i; j += 1) {
      dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  // debug: print dp array
  
  cout << dp[1][1] << endl;
  return 0;
}
