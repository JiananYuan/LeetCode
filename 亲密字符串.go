func buddyStrings(s string, goal string) bool {
    len_s := len(s)
    len_g := len(goal)
    // 长度不相同
    if len_s != len_g {
        return false
    }
    // 两字符串一致
    if s == goal {
        return is_repeated(s)
    }
    // 两字符串不一致
    // 第一个不同点
    first := -1
    // 第二个不同点
    second := -1
    // 有几次不同
    cnt := 0
    for i := 0; i < len_s; i += 1 {
        if s[i] != goal[i] {
            cnt += 1
            if first == -1 {
                first = i
            } else if first != -1 && second == -1 {
                second = i
            }
        }
        if cnt > 2 {
            break
        }
    }
    // cnt 如果不是两个, 则无法恢复
    if cnt != 2 {
        return false
    } else {
        // 是两个, 则尝试交换判断
        return swap_and_equal(first, second, s, goal)
    }
}

func swap_and_equal(i, j int, s, goal string) bool {
    byte_s := []byte(s)
    ch := byte_s[i]
    byte_s[i] = byte_s[j]
    byte_s[j] = ch
    ss := string(byte_s)
    return ss == goal
}

func is_repeated(s string) bool {
    book_s := make([]int, 26)
    leng := len(s)
    for i := 0; i < leng; i += 1 {
        book_s[ s[i] - 'a'] += 1
    }
    is_repeated := false
    for i := 0; i < 26; i += 1 {
        if book_s[i] >= 2 {
            is_repeated = true
        }
    }
    return is_repeated
}
