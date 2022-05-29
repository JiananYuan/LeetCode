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
                for (int i = 1; i < w_len; i += 1) {
                    if (w[i] >= '0' && w[i] <= '9') {

                    }
                    else {
                        need = false;
                        break;
                    }
                }
                if (need) {
                    long long num = atoll(w.substr(1).c_str());
                    num_vec.push_back(num);
                    vec.emplace_back("YJN");
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
        int u = 0;
        int vec_len = vec.size();
        for (int i = 1; i < vec_len; i += 1) {
            if (vec[i] == "YJN") {
                ans = ans + " $"
            }
            else {
                ans = ans + " " + vec[i];
            }
        }
        return ans;
    }
};
