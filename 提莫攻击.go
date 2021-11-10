func findPoisonedDuration(timeSeries []int, duration int) int {
    len := len(timeSeries)
    ans := 0
    for i := 0; i < len - 1; i += 1 {
        // 有覆盖
        if timeSeries[i] + duration > timeSeries[i+1] {
            ans += (timeSeries[i + 1] - timeSeries[i])
        } else {
            ans += duration
        }
    }
    ans += duration
    return ans
}
