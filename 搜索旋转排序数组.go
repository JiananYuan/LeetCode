func search(nums []int, target int) int {
    left := 0
    right := len(nums) - 1
    for left < right {
        mid := (left + right) / 2
        if nums[mid] < nums[right] {
            right = mid - 1
        } else if nums[mid] >= nums[left] {
            left = mid + 1
        }
    }
    split := left
    // fmt.Println(split)
    // fmt.Println(nums[split])
    if split == 0 {
        return binarySearch(nums, 0, len(nums) - 1, target)
    }
    if target < nums[0] {
        return binarySearch(nums, split, len(nums) - 1, target)
    } else {
        // fmt.Print("here")
        return binarySearch(nums, 0, max(0, split - 1), target)
    }
}

func binarySearch(nums []int, left int, right int, target int) int {
    // fmt.Println(left)
    // fmt.Println(right)
    for left <= right {
        mid := (left + right) / 2
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
