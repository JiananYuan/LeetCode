func buddyStrings(s string, goal string) bool {
    len_s := len(s)
    len_g := len(goal)
    // 剪枝_1
    if len_s != len_g {
        return false
    }
    book_s [26]int
    book_g [26]int
    for i := 0; i < len_s; i += 1 {
        book_s[ s[i] - 'a' ] += 1
        book_g[ goal[i] - 'a' ] += 1
    }
    // 剪枝_2
    for i := 0; i < 26; i += 1 {
        if book_s[i]
    }
    for i := 0; i < len_s; i += 1 {
        for j := i + 1; j < len_s; j += 1 {
            if swap_and_equal(i, j, s, goal) {
                return true 
            }
        }
    }
    return false
}

func swap_and_equal(i, j int, s, goal string) bool {
    byte_s := []byte(s)
    ch := byte_s[i]
    byte_s[i] = byte_s[j]
    byte_s[j] = ch
    ss := string(byte_s)
    return ss == goal
}
