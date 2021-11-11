var ans [][]int

func permuteUnique(nums []int) [][]int {
    ans = ans[ : 0]
	length := len(nums)
	visit := [10]bool{}
	var current []int
	solve(nums, length, visit, current)
	return ans
}

func solve(nums []int, length int, visit [10]bool, current []int) {
	if len(current) == length {
		leng := len(ans)
		for i := 0; i < leng; i += 1 {
			if isSame(current, ans[i]) {
				return
			}
		}
		ans = append(ans, current)
		return
	}
	for i := 0; i < length; i += 1 {
		if visit[i] == false {
			visit[i] = true
			current = append(current, nums[i])
			solve(nums, length, visit, current)
			current = current[ : len(current) - 1]
			visit[i] = false
		}
	}
}

func isSame(a []int, b []int) bool {
	lena := len(a)
	lenb := len(b)
	if lena != lenb {
		return false
	}
	for i := 0; i < lena; i += 1 {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > anss;
        int length = int(nums.size());
        bool visit[10] = {0};
        vector<int> current;
        solve(nums, length, visit, current, anss);
        vector<vector<int> > ans;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            ans.emplace_back(*it);
        }
        return ans;
    }

    void solve(vector<int>& nums, int& length, bool visit[], vector<int>& current, set<vector<int> >& ans) {
        if (int(current.size()) == length) {
            ans.insert(current);
            return;
        }
        for (int i = 0; i < length; i += 1) {
            if (visit[i] == false) {
                visit[i] = true;
                current.push_back(nums[i]);
                solve(nums, length, visit, current, ans);
                current.pop_back();
                visit[i] = false;
            }
        }
    }

};
