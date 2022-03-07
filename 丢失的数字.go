func missingNumber(nums []int) int {
    ans := 0
    for i, num := range nums {
        ans ^= num
        ans ^= (i + 1)
    }
    return ans
}

