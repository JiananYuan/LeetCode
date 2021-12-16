/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
    return dfs(p, q)
}

func dfs(p *TreeNode, q *TreeNode) bool {
    if p != nil && q != nil {
        if (p.Val == q.Val) {
            return dfs(p.Left, q.Left) && dfs(p.Right, q.Right)
        }
    } else if p == nil && q == nil {
        return true
    } else {
        return false
    }
    return false
}
