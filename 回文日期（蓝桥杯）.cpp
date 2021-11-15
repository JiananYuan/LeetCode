#include <iostream>
#include <sstream>
using namespace std;

int day_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string reverse_num(int num) {
    int ans = 0;
    while (num != 0) {
        ans = ans * 10 + (num % 10);
        num /= 10;
    }
    stringstream ss;
    int tmp = ans;
    int len = 0;
    while (tmp != 0) {
        tmp /= 10;
        len += 1;
    }
    for (int i = 0; i < 4 - len; i += 1) {
        ss << 0;
    }
    ss << ans;
    return ss.str();
}

bool is_ABAB(string num) {
    return (num[0] == num[2]) && (num[1] == num[3]);
}

int main() {
    // 输入日期
    int N;
    cin >> N;
    // 分离年份
    int year = N / 10000;
    // 存储答案
    int ans_1 = 0, ans_2 = 0;
    // 是否都已经找到
    bool is_ans_1_found = false, is_ans_2_found = false;
    // 以年份为粒度查找
    for (int i = year; !is_ans_1_found || !is_ans_2_found; i += 1) {
        // 得到月份和日期的表示格式 mm/dd
        string after_year = reverse_num(i);
        // 分离月份和日期
        int month = (after_year[0] - '0') * 10 + (after_year[1] - '0');
        int day =  (after_year[2] - '0') * 10 + (after_year[3] - '0');
        if (month > 12) {
            continue;
        }
        // 题目的限制，此处就可以不用再多做判断
        if (day > day_of_month[month]) {
            continue;
        }
        int ans = i * 10000 + month * 100 + day;
        // 不可以比当前日期小
        if (ans <= N) {
            continue;
        }
        if (!is_ans_1_found) {
            ans_1 = ans;
            is_ans_1_found = true;
        }
        if (!is_ans_2_found && is_ABAB(after_year)) {
            ans_2 = ans;
            is_ans_2_found = true;
        }
    }
    cout << ans_1 << endl << ans_2 << endl;
    return 0;
}
