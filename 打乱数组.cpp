class Solution {
private:
    vector<int> arr;
    vector<int> back;
    int length;

public:
    Solution(vector<int>& nums) {
        length = int(nums.size());
        for (int i = 0; i < length; i += 1) {
            arr.push_back(nums[i]);
            back.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return back;
    }
    
    vector<int> shuffle() {
        // srand((unsigned)time(nullptr));
        vector<int> shuffle_vec;
        vector<int> tmp(arr);
        for (int i = 0; i < length; i += 1) {
            int rand_id = rand() % (length - i);
            shuffle_vec.push_back(tmp[rand_id]);
            swap(tmp[rand_id], tmp[length - 1 - i]);
        }
        return shuffle_vec;
    }
};
