func plusOne(digits []int) []int {
    len := len(digits)
    stepIn := 0
    for i := len - 1; i >= 0; i -= 1 {
        num := digits[i]
        if i == len - 1 {
            num += 1
        }
        if num + stepIn >= 10 {
            num = (num + stepIn) % 10
            stepIn = 1
        } else {
            num += stepIn
            stepIn = 0
        }
        digits[i] = num
    }
    // last step in 
    if stepIn == 1 {
        digits = append([]int{1}, digits...)
    }
    return digits
}
