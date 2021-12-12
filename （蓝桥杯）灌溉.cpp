#include <iostream>
#include <queue>
#include <string.h>
const int N = 104;
using namespace std;

bool map[N][N];
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct point {
  int x;
  int y;
  point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};

inline bool check_in_board(int& n, int& m, int& i, int& j) {
  return i >= 0 && j >= 0 && i <= n && j <= m;
}

int main()
{
  memset(map, 0, sizeof(bool) * N * N);
  int n, m;
  cin >> n >> m;
  int t;
  cin >> t;
  queue<point> water;
  while (t--) {
    int x, y;
    cin >> x >> y;
    water.push(point(x, y));
    map[x][y] = true;
  }
  int k;
  cin >> k;
  while (k-- && !water.empty()) {
    int kk = int(water.size());
    while (kk--) {
        point wp = water.front();
        water.pop();
        for (int i = 0; i < 4; i += 1) {
          int nx = wp.x + dir[i][0];
          int ny = wp.y + dir[i][1];
          if (check_in_board(n, m, nx, ny) && map[nx][ny] == false) {
            map[nx][ny] = true;
            water.push(point(nx, ny));
          }
        }
        // for (int i = 1; i <= n; i += 1) {
        //     for (int j = 1; j <= m; j += 1) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= m; j += 1) {
      if (map[i][j]) {
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
