type Solution struct {
    matrix [][]int
    selected []int
    selected_num int
}


func Constructor(m int, n int) Solution {
    var s Solution
    s.matrix = make([][]int, m)
    for i := 0; i < m; i += 1 {
        s.matrix[i] = make([]int, n)
    }
    s.selected = make([]int, m * n)
    for i := 0; i < m; i += 1 {
        for j := 0; j < n; j += 1 {
            s.selected[i * n + j] = i * n + j
        }
    }
    s.selected_num = m * n
    return s
}


func (this *Solution) Flip() []int {
    m := len(this.matrix)
    var n int
    if m > 0 {
        n = len(this.matrix[0])
    }
    rand_id := rand.Intn(this.selected_num)
    swap := func(rand_id int, selected_num int) {
        tmp := this.selected[rand_id]
        this.selected[rand_id] = this.selected[this.selected_num - 1]
        this.selected[this.selected_num - 1] = tmp
    }
    rand_num := this.selected[rand_id]
    swap(rand_id, this.selected_num)
    this.selected_num -= 1
    row := rand_num / n
    col := rand_num % n
    this.matrix[row][col] = 1
    return []int{ row, col }
}


func (this *Solution) Reset()  {
    m := len(this.matrix)
    var n int
    if m > 0 {
        n = len(this.matrix[0])
    }
    for i := 0; i < m; i += 1 {
        for j := 0; j < n; j += 1 {
            this.matrix[i][j] = 0
        }
    }
    this.selected_num = m * n
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(m, n);
 * param_1 := obj.Flip();
 * obj.Reset();
 */
