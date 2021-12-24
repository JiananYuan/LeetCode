#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000;
int datas[N + 1];

void generate() {
    srand((unsigned)time(nullptr));
    for (int i = 1; i <= N; i += 1) {
        datas[i] = rand() % N;
    }
    sort(datas + 1, datas + 1 + N);
}

int main() {
    generate();
    time_t st = clock();
    for (int j = 1; j <= (N >> 1); j += 1) {
        int i = 0, base = 0, x = rand() % N;
        while (true) {
            int index = base + (1 << i);
            if (index >= N) {
                base = base + (1 << (i - 1));
                i = 0;
                index = base + (1 << i);
            }
            if (base >= N || index >= N) {
                cout << "not found" << endl;
                break;
            }
            int num = datas[index];
            if (x == num) {
                cout << "locate at " << index << endl;
                break;
            }
            else if (x > num) {
                i += 1;
            }
            else {
                if (i == 0) {
                    cout << "not found" << endl;
                    break;
                }
                base = base + (1 << (i - 1));
                i = 0;
            }
        }
    }
    time_t en = clock();
    cout << "time: " << (en - st) / 1000.0 << "s\n";
    return 0;
}
