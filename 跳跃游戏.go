func canJump(nums []int) bool {
    lenn := len(nums)
    rightmost := 0
    for i := 0; i < lenn; i += 1 {
        if i <= rightmost {
            rightmost = max(rightmost, i + nums[i])
            if rightmost >= lenn - 1 {
                break
            }
        }
    }
    if rightmost >= lenn - 1 {
        return true
    } else {
        return false
    }
}

func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}
