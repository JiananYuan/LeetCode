func findAnagrams(s string, p string) []int {
    p_count_arr := make([]int, 26)
    p_len := len(p)
    s_len := len(s)
    // 及时止损
    if p_len > s_len {
        return []int{}
    }
    for i := 0; i < p_len; i += 1 {
        p_count_arr[ p[i] - 'a' ] += 1
    }
    ans_vec := make([]int, s_len)
    ptr := 0
    for i := 0; i <= s_len - p_len; i += 1 {
        // 及时止损
        if p_count_arr[ s[i] - 'a' ]  == 0 {
            continue
        }
        tmp := s[i : i + p_len]
        tmp_count_arr := make([]int, 26)
        for j := 0; j < p_len; j += 1 {
            tmp_count_arr[ tmp[j] - 'a' ] += 1
        }
        is_consistent := true
        for j := 0; j < 26; j += 1 {
            if tmp_count_arr[j] != p_count_arr[j] {
                is_consistent = false
                break
            }
        }
        if is_consistent {
            ans_vec[ptr] = i
            ptr += 1
        }
    }
    return ans_vec[0 : ptr]
}
