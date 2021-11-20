func findLHS(nums []int) int {
	length := len(nums)
    visited := make(map[int]bool)
	ans_len := 0
	for i := 0; i < length; i += 1 {
        if visited[ nums[i] ] {
            continue
        }
		is_upper_appeared, upper_len := solve_len(nums, nums[i], nums[i] + 1, i + 1, length)
		if is_upper_appeared {
			ans_len = max(ans_len, upper_len)
		}
		is_lower_appeared, lower_len := solve_len(nums, nums[i], nums[i] - 1, i + 1, length)
		if is_lower_appeared {
			ans_len = max(ans_len, lower_len)
		}
        visited[ nums[i] ] = true
	}
	return ans_len
}

func solve_len(nums []int, origin_num int, bound_target int, begin int, end int) (bool, int) {
	tmp_len := 1
	is_bound_appeared := false
	for i := begin; i < end; i += 1 {
		if nums[i] == bound_target {
			is_bound_appeared = true
		}
		if bound_target > origin_num && nums[i] - origin_num <= 1 && nums[i] - origin_num >= 0 {
			tmp_len += 1
		} else if bound_target < origin_num && origin_num - nums[i] <= 1 && origin_num - nums[i] >= 0 {
			tmp_len += 1
		}
	}
	return is_bound_appeared, tmp_len
}

func max(a int, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}
