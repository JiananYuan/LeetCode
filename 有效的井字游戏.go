func validTicTacToe(board []string) bool {
    if check_XO_num(board) == false {
        return false
    }
    if check_repeated_3chess(board) == false {
        return false
    }
    return true
}

func check_XO_num(board []string) bool {
    O_num := 0
    X_num := 0
    for i := 0; i < 3; i += 1 {
        for j := 0; j < 3; j += 1 {
            if board[i][j] == 'O' {
                O_num += 1
            }
            if board[i][j] == 'X' {
                X_num += 1
            }
        }
    }
    if O_num - X_num >= 2 || X_num - O_num >= 2 {
        return false
    }
    return true
}

func check_repeated_3chess(board []string) bool {
    hasWin := false
    for i := 0; i < 3; i += 1 {
        if board[i][0] == board[i][1] && board[i][1] == board[i][2] {
            // 多次胜利是不合法的
            if hasWin {
                return false
            }
            hasWin = true
        }
    }
    for i := 0; i < 3; i += 1 {
        if board[0][i] == board[1][i] && board[1][i] == board[2][i] {
            // 多次胜利是不合法的
            if hasWin {
                return false
            }
            hasWin = true
        }
    }
    if board[0][0] == board[1][1] && board[1][1] == board[2][2] {
        // 多次胜利是不合法的
        if hasWin {
            return false
        }
        hasWin = true
    }
    if board[0][2] == board[1][1] && board[1][1] == board[2][0] {
        // 多次胜利是不合法的
        if hasWin {
            return false
        }
        hasWin = true
    }

    return true
}
