func majorityElement(nums []int) []int {
    mp := make(map[int]int)
    for _, num := range nums {
        _, ok := mp[num]
        if ok {
            mp[num] += 1
        } else {
            mp[num] = 1
        }
    }
    len := len(nums)
    ans := []int{}
    for num := range mp {
        if mp[num] > (len / 3) {
            ans = append(ans, num)
        }
    }
    return ans
}
