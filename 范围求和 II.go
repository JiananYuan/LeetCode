func maxCount(m int, n int, ops [][]int) int {
    minx := 0x7fffffff
    miny := minx
    lenx := len(ops)
    if lenx == 0 {
        return m * n
    }
    for i := 0; i < lenx; i += 1 {
        minx = min(minx, ops[i][0])
        miny = min(miny, ops[i][1])
    }
    return minx * miny
}

func min(a int, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

