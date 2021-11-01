func distributeCandies(candyType []int) int {
    st := map[int]bool{}
    for _, num := range candyType {
        st[num] = true
    }
    return min(len(st), len(candyType) / 2)
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}
