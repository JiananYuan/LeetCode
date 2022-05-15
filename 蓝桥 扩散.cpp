#include <iostream>
#include <queue>
#define N 10000
using namespace std;

bool color_map[N][N];
int dir[][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

struct node {
    int x;
    int y;
    int step;

    node(int _x, int _y, int _step) {
        x = _x;
        y = _y;
        step = _step;
    }
};


int main() {
    // color_map[0][0] = color_map[2020][11] = color_map[11][14] = color_map[2000][2000] = true;
    queue<node> q;
    q.push(node(0, 0, 0));
    q.push(node(2020, 11, 0));
    q.push(node(11, 14, 0));
    q.push(node(2000, 2000, 0));
    int ans = 0;
    while (!q.empty()) {
        node nd = q.front();
        q.pop();
        if (nd.step == 2) {
            break;
        }
        color_map[nd.x][nd.y] = true;
        ans += 1;
        for (int i = 0; i < 4; i += 1) {
            int tx = nd.x + dir[i][0];
            int ty = nd.y + dir[i][1];
            if (tx >= 0 && ty >= 0 && color_map[tx][ty] == false) {
                color_map[tx][ty] = true;
                q.push(node(tx, ty, nd.step + 1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
