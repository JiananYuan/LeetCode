var ans int
// 记录node 节点所在子树的总和
var record map[*TreeNode]int

func findTilt(root *TreeNode) int {
    ans = 0
    record = make(map[*TreeNode]int)
	solve(root)
	return ans
}

// 后序遍历
func solve(node *TreeNode) int {
	if node == nil {
		return 0
	}
	if _, exist := record[node]; exist {
		return record[node]
	}
	left := solve(node.Left)
	right := solve(node.Right)
    ans += abs(left, right)
	record[node] = left + right + node.Val
	return record[node]
}

func abs(a int, b int) int {
	if a > b {
		return a - b
	} else {
		return b - a
	}
}
