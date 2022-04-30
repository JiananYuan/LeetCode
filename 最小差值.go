func smallestRangeI(nums []int, k int) int {
    maxx := -1
    minx := 100000
    for i := 0; i < len(nums); i += 1 {
        if maxx < nums[i] {
            maxx = nums[i]
        }
        if minx > nums[i] {
            minx = nums[i]
        }
    }
    if maxx - minx >= 2 * k {
        return (maxx - k) - (minx + k)
    } else {
        return 0
    }
}
