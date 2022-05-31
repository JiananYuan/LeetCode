class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string w;
        vector<long long> num_vec;
        string ans = "";
        bool is_first = true;
        while (ss >> w) {
            if (!is_first) {
                ans = ans + " ";
            }
            is_first = false;
            // 判断是否为价格的格式
            if (w[0] == '$') {
                bool need = true;
                int w_len = w.length();
                if (w_len == 1) {
                    ans += w;
                    continue;
                }
                for (int i = 1; i < w_len; i += 1) {
                    if (w[i] >= '0' && w[i] <= '9') {

                    }
                    else {
                        need = false;
                        break;
                    }
                }
                if (need) {
                    double tmp = stod(w.substr(1).c_str());
                    tmp -= tmp * discount * 0.01;
                    tmp = (round(tmp * 100)) * 0.01;
                    ostringstream oss;
                    oss << fixed << setprecision(2) << tmp;
                    ans += "$" + oss.str();
                }
                else {
                    ans += w;
                }
            }
            else {
                ans += w;
            }
        }
        return ans;
    }
};
