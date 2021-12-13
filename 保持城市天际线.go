func maxIncreaseKeepingSkyline(grid [][]int) int {
	row := len(grid)
	col := row
	height_row := make([]int, row)
	height_col := make([]int, col)
	for i := 0; i < row; i += 1 {
		max_h := -1
		for j := 0; j < col; j += 1 {
			max_h = max(max_h, grid[i][j])
		}
		height_row[i] = max_h
	}
	for i := 0; i < col; i += 1 {
		max_h := -1
		for j := 0; j < row; j += 1 {
			max_h = max(max_h, grid[j][i])
		}
		height_col[i] = max_h
	}
	ans := 0
	for i := 0; i < row; i += 1 {
		for j := 0; j < col; j += 1 {
			ans += min(height_row[i], height_col[j]) - grid[i][j]
		}
	}
	return ans
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
