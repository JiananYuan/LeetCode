func solve(node *TreeNode, cnt *int, k int) (int, bool)  {
	if node == nil {
		return -1, false
	}
	// 中序遍历
	val, found := solve(node.Left, cnt, k)
	if found {
		return val, true
	}
	*cnt = *cnt + 1
	if *cnt == k {
		return node.Val, true
	}
	val, found = solve(node.Right, cnt, k)
	if found {
		return val, true
	}
	return -1, false
}

func kthSmallest(root *TreeNode, k int) int {
	cnt := 0
	ans, found := solve(root, &cnt, k)
	if found {
		return ans
	} else {
		return 0
	}
}
