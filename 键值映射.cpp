class MapSum {
private:
    unordered_map<string, int> inner_map;

public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        // 首次出现
        if (inner_map.count(key) == 0) {
            inner_map.insert(make_pair(key, val));
        } 
        // 之前出现，现在更新
        else {
            inner_map[key] = val;
        }
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto it = inner_map.begin(); it != inner_map.end(); it++) {
            string key = it -> first;
            if (key.find(prefix) == 0) {
                sum += inner_map[key];
            }
        }
        return sum;
    }
};
