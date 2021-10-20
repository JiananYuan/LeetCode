func maxNum(nums []int) (int, int) {
    len := len(nums)
    max := nums[0]
    id := 0
    for i := 1; i < len; i += 1 {
        if nums[i] > max {
            max = nums[i]
            id = i
        }
    }
    return max, id
}

func minNum(nums []int) (int, int) {
    len := len(nums)
    min := nums[0]
    id := 0
    for i := 1; i < len; i += 1 {
        if nums[i] < min {
            min = nums[i]
            id = i
        }
    }
    return min, id
}

func increment(nums []int, exclude_id int, delta int) {
    len := len(nums)
    for i := 0; i < len; i += 1 {
        if i != exclude_id {
            nums[i] += delta
        }
    }
}

func minMoves(nums []int) int {
    cnt := 0
    max := 0
    min := 0
    max_id := 0
    min_id := 1  // differ at first init
    for max_id != min_id {
        max, max_id = maxNum(nums)
        min, min_id = minNum(nums)
        cnt += (max - min)
        increment(nums, max_id, max - min)
    }  
    return cnt
}
