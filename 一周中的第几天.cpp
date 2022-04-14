class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weekday = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
        int date[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = 365 * (year - 1971) + (year - 1968 - 1) / 4;
        for (int i = 1; i < month; i += 1) {
            days += date[i];
        }
        days += day;
        if (is_leap(year) && month > 2) {
            days += 1;
        }
        return weekday[(days + 3) % 7];
    }

    inline bool is_leap(int year) {
        if (year % 400 == 0) {
            return true;
        }
        if ((year % 4 == 0) && (year % 100 != 0)) {
            return true;
        }
        return false;
    }
};

