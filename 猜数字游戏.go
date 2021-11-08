func getHint(secret string, guess string) string {
    cnt_secret := [10]int{}
    cnt_guess := [10]int{}
    slen := len(secret)
    a := 0
    b := 0
    for i := 0; i < slen; i += 1 {
        if secret[i] == guess[i] {
            a += 1
            continue
        }
        num_secret := secret[i] - '0'
        num_guess := guess[i] - '0';
        cnt_secret[num_secret] += 1
        cnt_guess[num_guess] += 1
    }
    for i := 0; i < 10; i += 1 {
        b += min(cnt_guess[i], cnt_secret[i]);
    }
    return strconv.Itoa(a) + "A" + strconv.Itoa(b) + "B"
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}
