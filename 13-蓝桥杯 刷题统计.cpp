#include<iostream>
using namespace std;
int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    long long weeks = n / (5 * a + 2 * b);
    n -= weeks * (5 * a + 2 * b);
    long long days = weeks * 7;
    int cnt = 5;
    while (cnt != 0 && n > 0) {
        cnt -= 1;
        n -= a;
        days += 1;
    }
    cnt = 2;
    while (cnt != 0 && n > 0) {
        cnt -= 1;
        n -= b;
        days += 1;
    }
    cout << days << "\n";
    return 0;
}
