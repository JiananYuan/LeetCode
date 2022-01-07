#include <iostream>
using namespace std;

int maxx = 0;

void dfs(int team[][6], bool mark[], int ballpos, int sum) {
  if (ballpos == 6) {
    maxx = max(maxx, sum);
    return;
  }
  for (int i = 0; i < 20; i += 1) {
    if (!mark[i]) {
      mark[i] = true;
      dfs(team, mark, ballpos + 1, sum + team[i][ballpos]);
      mark[i] = false;
    }
    
  }
}

int main()
{
  // 请在此输入您的代码
  int team[20][6] = {
    {1,  97, 90, 0,  0,  0},
    {2,  92, 85, 96, 0,  0},
    {3,  0,  0,  0,  0,  93},
    {4,  0,  0,  0,  80, 86},
    {5,  89, 83, 97, 0,  0},
    {6,  82, 86, 0,  0,  0},
    {7,  0,  0,  0,  87, 90},
    {8,  0,  97, 96, 0,  0},
    {9,  0,  0,  89, 0,  0},
    {10, 95, 99, 0,  0,  0},
    {11, 0,  0,  96, 97, 0},
    {12, 0,  0,  0,  93, 98},
    {13, 94, 91, 0,  0,  0},
    {14, 0,  83, 87, 0,  0},
    {15, 0,  0,  98, 97, 98},
    {16, 0,  0,  0,  93, 86},
    {17, 98, 83, 99, 98, 81},
    {18, 93, 87, 92, 96, 81},
    {19, 0,  0,  0,  89, 92},
    {20, 0,  99, 96, 95, 81}
  };
  bool mark[20] = { false };
  dfs(team, mark, 1, 0);
  cout << maxx << endl;
  return 0;
}
