#include <iostream>
using namespace std;

int main() {
    int n = 10000;
    int minutes = 0;
    // bool is_running = true;
    while (true) {
        // if (is_running) {
        //     n -= 600;    
        // }
        // else {
        //     n += 300;
        // }
        // is_running = !is_running;
        if (n >= 600) {
            n -= 300;  // -600 + 300
            minutes += 2;
        }
        else {
            break;
        }
        // n += 300;
    }
    int s = minutes * 60;
    cout << s + n / 10 << endl;
    // if (is_running) {
    //     cout << s + n / 10 << endl;
    // }
    // else {
    //     cout << s << endl;
    // }
    return 0;
}
