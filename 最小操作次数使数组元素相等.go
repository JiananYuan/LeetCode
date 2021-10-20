func minNum(nums []int) int {
    len := len(nums)
    min := nums[0]
    for i := 1; i < len; i += 1 {
        if nums[i] < min {
            min = nums[i]
        }
    }
    return min
}

func sumDistance(nums []int, min int) int {
    sum := 0
    for _, x := range nums {
        sum += (x - min)
    }
    return sum
}

func minMoves(nums []int) int {
    min := minNum(nums)
    ans := sumDistance(nums, min)
    return ans
}
