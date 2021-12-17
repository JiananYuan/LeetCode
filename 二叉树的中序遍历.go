/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    ans := []int{}
    var mid_traverse func(node *TreeNode) 
    mid_traverse = func(node *TreeNode) {
        if node != nil {
            mid_traverse(node.Left)
            ans = append(ans, node.Val)
            mid_traverse(node.Right)
        }
    }
    mid_traverse(root)
    return ans
}
