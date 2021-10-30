func singleNumber(nums []int) []int {
    rec := make(map[int]int)
    len := len(nums)
    for i := 0; i < len; i += 1 {
        num := nums[i]
        rec[num] += 1
    }
    ans := []int{}
    for key := range rec {
        if rec[key] == 1 {
            ans = append(ans, key)
        }
    }
    return ans
}
