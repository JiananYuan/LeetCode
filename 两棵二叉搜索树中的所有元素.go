/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
    var arr []int
    var traverse func(node *TreeNode)
    traverse = func(node *TreeNode) {
        if node == nil {
            return
        }
        tmp := append(arr, node.Val)
        arr = tmp
        traverse(node.Left)
        traverse(node.Right)
    }
    traverse(root1)
    traverse(root2)
    sort.Sort(sort.IntSlice(arr))
    return arr
}
