func lengthOfLastWord(s string) int {
    slen := len(s)
    i := slen - 1
    for ; i >= 0 && s[i] == ' '; i -= 1 {

    }
    cnt := 0
    for ; i >= 0 && s[i] != ' '; i -= 1 {
        cnt += 1
    }
    return cnt
}
