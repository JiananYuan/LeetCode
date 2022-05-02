func generateParenthesis(n int) []string {
    var myfunc func(left_cnt int, right_cnt int, str string, sum int) 
    var ans []string
    myfunc = func(left_cnt int, right_cnt int, str string, sum int) {
        if left_cnt == n && right_cnt == n {
            tmp := append(ans, str)
            ans = tmp
            return
        }
        if left_cnt < n {
            myfunc(left_cnt + 1, right_cnt, str + "(", sum + 1)
        }
        if right_cnt < n && sum > 0 {
            myfunc(left_cnt, right_cnt + 1, str + ")", sum - 1)
        }
    }
    myfunc(0, 0, "", 0)
    return ans
}
