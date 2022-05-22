#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long ll;
map<char, ll> mp;
map<ll, char> r_mp;

// k进制转化为 10进制
ll change_10(ll step, string str) {
    int len = str.length();
    ll rec = 0;
    for (int i = 0; i < len; i += 1) {
        rec = rec * step + mp[ str[i] ];
    }
    return rec;
}

string change_k(ll step, ll num) {
    if (num == 0) {
        return "0";
    }
    string rec = "";
    while (num) {
        rec = r_mp[num % step] + rec;
        num /= step;
    }
    return rec;
}

int main() {
    for (char i = '0'; i <= '9';i += 1) {
        mp[i] = i - '0';
        r_mp[i - '0'] = i;
    }
    for (char i = 'A'; i <= 'Z';i += 1) {
        mp[i] = i - 'A' + 10;
        r_mp[i - 'A' + 10] = i;
    }

    int n;
    cin >> n;
    ll num = 0;
    ll step = 10;
    string last_op = "";
    while (n--) {
        string op;
        cin >> op;
        if (op == "NUM") {
            string tmp;
            cin >> tmp;
            if (last_op == "ADD") {
                ll r = change_10(step, tmp);
                num += r;
            }
            else if (last_op == "SUB") {
                ll r = change_10(step, tmp);
                num -= r;
            }
            else if (last_op == "MUL") {
                ll r = change_10(step, tmp);
                num *= r;
            }
            else if (last_op == "DIV") {
                ll r = change_10(step, tmp);
                num /= r;
            }
            else if (last_op == "MOD") {
                ll r = change_10(step, tmp);
                num %= r;
            }
            else {
                num = change_10(step, tmp);
            }
        }
        else if (op == "CHANGE") {
            cin >> step;
        }
        else if (op == "EQUAL") {
            cout << "debug: " << num << endl;
            cout << "debug: " << step << endl;
            string ans = change_k(step, num);
            cout << ans << endl;
        }
        else if (op == "CLEAR") {
            num = 0;
        }
        else {
            last_op = op;
        }
    }
    return 0;
}
