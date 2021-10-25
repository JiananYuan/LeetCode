func searchMatrix(matrix [][]int, target int) bool {
    m := len(matrix)
    n := len(matrix[0])
    for i, j := 0, n-1; i >= 0 && j >= 0 && i < m && j < n; {
        if matrix[i][j] == target {
            return true
        } else if matrix[i][j] > target {
            j -= 1
        } else if matrix[i][j] < target {
            i += 1
        }
    }
    return false
}
