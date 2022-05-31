class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string w;
        vector<string> vec;
        vector<long long> num_vec;
        while (ss >> w) {
            // 判断是否为价格的格式
            if (w[0] == '$') {
                bool need = true;
                int w_len = w.length();
                if (w_len == 1) {
                    vec.push_back(w);
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
                    double tmp = atof(w.substr(1).c_str());
                    tmp -= tmp * discount / 100;
                    printf("%.6f\n", tmp);
                    // printf("%.6f\n", round(tmp * 100));
                    tmp = (round(tmp * 100)) / 100.0;
                    printf("%.6f\n", tmp);
                    // cout << tmp << endl;
                    string tmp_s = to_string(tmp);
                    int i = 0;
                    string ans = "";
                    for (i = 0; i < tmp_s.length(); i += 1) {
                        if (tmp_s[i] == '.') {
                            break;
                        }
                    }
                    if (i == tmp_s.length()) {
                        ans = tmp_s + ".00";
                    }
                    else {
                        ans = tmp_s.substr(0, i + 1);
                        for (int j = 1; j <= 2; j += 1) {
                            if (i + j < tmp_s.length()) {
                                ans += tmp_s[i + j];
                            }
                            else {
                                ans += "0";
                            }
                        }
                    }
                    vec.emplace_back("$" + ans);
                }
                else {
                    vec.emplace_back(w);
                }
            }
            else {
                vec.emplace_back(w);
            }
        }
        string ans = vec[0];
        int vec_len = vec.size();
        for (int i = 1; i < vec_len; i += 1) {
            ans = ans + " " + vec[i];
        }
        return ans;
    }
};
