func countBattleships(board [][]byte) int {
    rows := len(board)
    cols := len(board[0])
    var checkInBoard func(x int, y int) bool
    checkInBoard = func(x int, y int) bool {
        return x >= 0 && x < rows && y >= 0 && y < cols
    }
    mark := make([][]bool, rows)
    for i := 0; i < rows; i += 1 {
        mark[i] = make([]bool, cols)
    }
    count := 0
    for i := 0; i < rows; i += 1 {
        for j := 0; j < cols; j += 1 {
            if board[i][j] == 'X' && !mark[i][j] {
                count += 1
                mark[i][j] = true
                if checkInBoard(i + 1, j) && board[i + 1][j] == 'X' {
                    for k := i + 1; k < rows && board[k][j] == 'X'; k += 1 {
                        mark[k][j] = true
                    }
                } else if checkInBoard(i, j + 1) && board[i][j + 1] == 'X' {
                    for k := j + 1; k < cols && board[i][k] == 'X'; k += 1 {
                        mark[i][k] = true
                    }
                }
            }
        }
    }
    return count
}
