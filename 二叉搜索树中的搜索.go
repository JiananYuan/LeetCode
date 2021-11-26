/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func searchNode(node *TreeNode, val int) *TreeNode {
    if node == nil {
        return nil
    }
    if val == node.Val {
        return node
    }
    if val < node.Val {
        return searchNode(node.Left, val)
    } else if val > node.Val {
        return searchNode(node.Right, val)
    }
    return nil
}

func searchBST(root *TreeNode, val int) *TreeNode {
    return searchNode(root, val)
}
