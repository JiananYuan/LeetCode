func maxPower(s string) int {
    last_ch := s[0]
    i := 0
    s_len := len(s)
    max_power := 0
    j := 1
    for j < s_len {
        if s[j] == last_ch {
            max_power = max(max_power, j - i + 1)
        } else {
            i = j
            last_ch = s[j]
        }
        j += 1
    }
    if max_power == 0 {
        return 1
    }
    return max_power
}

func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}
