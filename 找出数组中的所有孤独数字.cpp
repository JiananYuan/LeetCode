class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> book;
        for (int num : nums) {
            book[num] += 1;
        }
        vector<int> ans;
        for (int num : nums) {
            if (book[num] == 1 && book.count(num - 1) == 0 && book.count(num + 1) == 0) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
