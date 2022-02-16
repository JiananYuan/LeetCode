class Solution {
public:
    int leap_month[13]= {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int none_month[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        // cout << year << " " << month << " " << day << endl;
        int ans = day;
        if (is_leap_year(year)) {
            for (int i = 0; i < month; i += 1) {
                ans += leap_month[i];
            }
        } 
        else {
            for (int i = 0; i < month; i += 1) {
                ans += none_month[i];
            }
        }
        return ans;
    }

    bool is_leap_year(int year) {
        if (year % 400 == 0) {
            return true;
        }
        if ((year % 4 == 0) && year % 100 != 0) {
            return true;
        }
        return false;
    }
};

