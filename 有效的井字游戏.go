var O_num int
var X_num int

func validTicTacToe(board []string) bool {
	O_num = 0
	X_num = 0
	if check_XO_num(board) == false {
		return false
	}
	if check_repeated_3chess(board) == false {
		return false
	}
	return true
}


func check_XO_num(board []string) bool {
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

	// O_num 恒不大于 X_num
	if O_num > X_num || X_num - O_num >= 2 {
		return false
	}
	return true
}


// 同种3棋子模式不可以存在，但是两种3棋子模式可以存在
func check_repeated_3chess(board []string) bool {
	// 优先判断2连珠
	for i := 0; i < 3; i += 1 {
		for j := 0; j < 3; j += 1 {
			s, _, _, _, _ := check_every_cell(board, i, j)
			if s == 2 {
				return true
			}
		}
	}
	// 再判断1连珠
	isWin := false
	var visit [3][3]bool
	for i := 0; i < 3; i += 1 {
		for j := 0; j < 3; j += 1 {
			if visit[i][j] == true {
				continue
			}
			s, s0, s1, s2, s3 := check_every_cell(board, i, j)
			if s == 1 {
				if isWin {
					return false
				}
				// X赢，但X_num == O_num，说明O多下了一次
				if board[i][j] == 'X' && X_num == O_num {
					return false
				}
				// O赢, 但X_num > O_num，说明O赢了之后X又多下了
				if board[i][j] == 'O' && X_num > O_num {
					return false
				}
				isWin = true
				if s0 {
					visit[i][0] = true
					visit[i][1] = true
					visit[i][2] = true
				}
				if s1 {
					visit[0][j] = true
					visit[1][j] = true
					visit[2][j] = true
				}
				if s2 {
					visit[0][0] = true
					visit[1][1] = true
					visit[2][2] = true
				}
				if s3 {
					visit[0][2] = true
					visit[1][1] = true
					visit[2][0] = true
				}
			}
		}
	}
	return true
}

// error, isWin
func check_every_cell(board []string, i int, j int) (int, bool, bool, bool, bool) {
	b := make([]bool, 4)
	b[0] = check_char(board, i, j) && board[i][j] == board[i][0] && board[i][j] == board[i][1] && board[i][j] == board[i][2]
	b[1] = check_char(board, i, j) && board[i][j] == board[0][j] && board[i][j] == board[1][j] && board[i][j] == board[2][j]
	if i == j {
		b[2] = check_char(board, i, j) && board[i][j] == board[0][0] && board[i][j] == board[1][1] && board[i][j] == board[2][2]
	}
	if i + j == 2 {
		b[3] = check_char(board, i, j) && board[i][j] == board[0][2] && board[i][j] == board[1][1] && board[i][j] == board[2][0]
	}
	mb := []int{ 0, 0, 0, 0 }
	for k := 0; k < 4; k += 1 {
		if b[k] {
			mb[k] = 1
		}
	}

	// 只可能有0, 1, 2 这三种情况
	return mb[0] + mb[1] + mb[2] + mb[3], b[0], b[1], b[2], b[3]
}

func check_char(board []string, i int, j int) bool {
	return board[i][j] == 'X' || board[i][j] == 'O'
}
