func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	for left < right {
		// special judge
		// 可以理解为提前退出
		if left > 0 && nums[left - 1] > nums[left] {
			break
		}
		mid := (left + right) >> 1
		if nums[mid] < nums[left] {
			right = mid - 1
		} else if nums[mid] >= nums[left] {
			left = mid + 1
		}
	}
	// split 指向分位点之后的第一个数
	split := left
	// special judge
	if split < len(nums) - 1 && nums[split + 1] < nums[split] {
		split += 1
	}
	if split == len(nums) - 1 {
		split = len(nums)
	}
	if target < nums[0] {
		// 最小搜索范围不能比总长度大
		return binarySearch(nums, min(split, len(nums) - 1), len(nums) - 1, target)
	} else {
		// 最小的搜索范围不能和比0小
		return binarySearch(nums, 0, max(split - 1, 0), target)
	}
}

func binarySearch(nums []int, left int, right int, target int) int {
	for left <= right {
		mid := (left + right) >> 1
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			return binarySearch(nums, left, mid - 1, target)
		} else if nums[mid] < target {
			return binarySearch(nums, mid + 1, right, target)
		}
	}
	return -1
}

func max(a int, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
